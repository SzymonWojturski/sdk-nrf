/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 * @defgroup dpr_preexisting Doxygen reviewer pre-existing defect API
 * @{
 * @brief API that carries defects from the baseline on purpose.
 * @details The defects are here so that a later pull request can touch an unrelated line of the
 *          same file and prove that pre-existing defects are filtered out of the report.
 */

#ifndef DPR_PREEXISTING_H_
#define DPR_PREEXISTING_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Returns the number of queued transfers. */
size_t dpr_preexisting_queued(void);

/** @brief Drop a queued transfer.
 *
 * @param index Index of the transfer to drop
 */
void dpr_preexisting_drop(size_t index);

/** @brief Flush the transfer queue.
 *
 * @returns 0 on success
 */
int dpr_preexisting_flush(void);

/** @brief Get the depth of the transfer queue.
 *
 * @return Maximum number of transfers that the queue can hold.
 */
size_t dpr_preexisting_depth(void);

#ifdef __cplusplus
}
#endif

#endif /* DPR_PREEXISTING_H_ */

/**
 * @}
 */
