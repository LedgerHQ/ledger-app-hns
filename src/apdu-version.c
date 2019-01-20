#include "apdu.h"
#include "ledger.h"

volatile uint16_t
hns_apdu_get_app_version(
  uint8_t p1,
  uint8_t p2,
  uint16_t len,
  volatile uint8_t *buf,
  volatile uint8_t *flags
) {
  if(p1 != 0)
    THROW(HNS_INCORRECT_P1);

  if(p2 != 0)
    THROW(HNS_INCORRECT_P2);

  if(len != 0)
    THROW(HNS_INCORRECT_LC);

  if (!ledger_pin_validated())
    THROW(HNS_SECURITY_CONDITION_NOT_SATISFIED);

  buf[0] = HNS_APP_MAJOR_VERSION;
  buf[1] = HNS_APP_MINOR_VERSION;
  buf[2] = HNS_APP_PATCH_VERSION;

  return 3;
}
