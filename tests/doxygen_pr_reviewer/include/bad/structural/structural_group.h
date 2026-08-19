/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 * @defgroup dpr_structural Doxygen reviewer structural API
 * @{
 * @brief Group that hosts the structural fixtures that do not test the group rules themselves.
 */

#ifndef DPR_STRUCTURAL_GROUP_H_
#define DPR_STRUCTURAL_GROUP_H_

/** @brief Start the structural fixture module.
 *
 * @retval 0       If the module was started.
 * @retval -EALREADY If the module was already running.
 */
int dpr_structural_start(void);

#endif /* DPR_STRUCTURAL_GROUP_H_ */

/** @} */
