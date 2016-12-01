/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include "src/actions/disruptive/pass.h"

#include <iostream>
#include <string>

#include "modsecurity/transaction.h"
#include "modsecurity/rule.h"
#include "modsecurity/rule_message.h"

namespace modsecurity {
namespace actions {
namespace disruptive {


bool Pass::evaluate(Rule *rule, Transaction *transaction, RuleMessage *rm) {
    transaction->m_it.status = 200;
    transaction->m_it.disruptive = false;
    transaction->m_it.url = NULL;
    transaction->m_it.log = NULL;
    transaction->m_it.pause = 0;

    transaction->debug(8, "Running action pass");

    return true;
}


}  // namespace disruptive
}  // namespace actions
}  // namespace modsecurity