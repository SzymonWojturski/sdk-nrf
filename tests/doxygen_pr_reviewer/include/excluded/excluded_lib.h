/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 * @defgroup dpr_excluded Doxygen reviewer excluded API
 * @{
 * @brief API that sits inside the INPUT tree but is listed in EXCLUDE.
 */

#ifndef DPR_EXCLUDED_LIB_H_
#define DPR_EXCLUDED_LIB_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Get the build identifier of the excluded module.
 *
 * @return Build identifier of the module.
 */
unsigned int dpr_excluded_build_id(void);

#ifdef __cplusplus
}
#endif

#endif /* DPR_EXCLUDED_LIB_H_ */

/**
 * @}
 */
