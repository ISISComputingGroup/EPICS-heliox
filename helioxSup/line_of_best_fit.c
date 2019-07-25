#include <stdlib.h>
#include <registryFunction.h>
#include <aSubRecord.h>
#include <epicsExport.h>
#include <errlog.h>
#include <gsl/gsl_fit.h>

static long line_of_best_fit(aSubRecord *prec)
{
    double cov00, cov01, cov11, chisq;
    int status;
    
    if (prec->noa != prec->nob) {
        errlogSevPrintf(errlogMajor, "line_of_best_fit: cannot calculate best fit as noa != nob");
        return 1;
    }
    
    status = gsl_fit_linear((double*) (prec->b), 1, (double*) (prec->a), 1, prec->noa, (double*) (prec->vala), (double*) (prec->valb), &cov00, &cov01, &cov11, &chisq);
    
    if (status != 0) {
        errlogSevPrintf(errlogMajor, "line_of_best_fit: GSL fit error: status = %d", status);
    }
    
    return status;
}

epicsRegisterFunction(line_of_best_fit);
