/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is Mozilla Foundation
 * Portions created by the Initial Developer are Copyright (C) 2011
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Mounir Lamouri <mounir.lamouri@mozilla.com> (Original Author)
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#ifndef mozilla_dom_sms_SmsCursor_h
#define mozilla_dom_sms_SmsCursor_h

#include "nsIDOMSmsCursor.h"
#include "nsCycleCollectionParticipant.h"
#include "nsCOMPtr.h"

class nsIDOMMozSmsMessage;
class nsIDOMMozSmsRequest;

namespace mozilla {
namespace dom {
namespace sms {

class SmsCursor : public nsIDOMMozSmsCursor
{
public:
  NS_DECL_CYCLE_COLLECTING_ISUPPORTS
  NS_DECL_NSIDOMMOZSMSCURSOR

  NS_DECL_CYCLE_COLLECTION_CLASS(SmsCursor)

  SmsCursor();
  SmsCursor(PRInt32 aListId, nsIDOMMozSmsRequest* aRequest);

  ~SmsCursor();

  void SetMessage(nsIDOMMozSmsMessage* aMessage);

  void Disconnect();

private:
  PRInt32                       mListId;
  nsCOMPtr<nsIDOMMozSmsRequest> mRequest;
  nsCOMPtr<nsIDOMMozSmsMessage> mMessage;
};

inline void
SmsCursor::SetMessage(nsIDOMMozSmsMessage* aMessage)
{
  mMessage = aMessage;
}

} // namespace sms
} // namespace dom
} // namespace mozilla

#endif // mozilla_dom_sms_SmsCursor_h
