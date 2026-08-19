/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @file
 * @defgroup dpr_syntactic Doxygen reviewer syntactic API
 * @{
 * @brief Descriptions and briefs in the forms that the style guide accepts and rejects.
 */

#ifndef DPR_BRIEF_FORMS_H_
#define DPR_BRIEF_FORMS_H_

#include <stddef.h>
#include <stdint.h>

/** Number of slots of the brief fixture. */
#define DPR_BRIEF_SLOTS 4

#define DPR_BRIEF_UNDOCUMENTED_SLOTS 8

/** Window of the brief fixture. */
struct dpr_brief_window {
	/** Start of the window in milliseconds */
	uint32_t start;

	/** Length of the window in milliseconds. */
	uint32_t length;
};

/**
 */
struct dpr_brief_undescribed {
	/** Identifier of the undescribed window. */
	uint8_t id;
};

/** Mode of the brief fixture. */
enum dpr_brief_mode {
	/** Window is closed. */
	DPR_BRIEF_MODE_CLOSED,

	/** Window is open. */
	DPR_BRIEF_MODE_OPEN,
};

/**
 */
enum dpr_brief_undescribed_mode {
	/** Mode is unknown. */
	DPR_BRIEF_UNDESCRIBED_UNKNOWN,
};

/** Open the window of the brief fixture and start collecting samples.
 *
 * @param[in] mode Mode to open the window in.
 *
 * @retval 0       If the window was opened.
 * @retval -EINVAL If @p mode is unknown.
 */
int dpr_brief_window_open(enum dpr_brief_mode mode);

/** @brief Returns the number of open windows.
 *
 * @return Number of open windows.
 */
size_t dpr_brief_open_count(void);

/** @brief Window helper.
 *
 * @return Identifier of the last opened window.
 */
uint8_t dpr_brief_last_id(void);

/** @brief Get the window length with a uint32_t argument and return an int.
 *
 * @param[in] length Length of the window in milliseconds.
 *
 * @retval 0       If the length was accepted.
 * @retval -EINVAL If @p length is zero.
 */
int dpr_brief_length_set(uint32_t length);

/** @brief Close the window of the brief fixture.
 *
 * The window keeps the collected samples until the next call that opens it again
 *
 * @retval 0       If the window was closed.
 * @retval -EALREADY If the window was already closed.
 */
int dpr_brief_window_close(void);

#endif /* DPR_BRIEF_FORMS_H_ */

/** @} */
