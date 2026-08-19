/*
 * Copyright (c) 2026 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

/**
 * @addtogroup dpr_syntactic
 * @{
 */

/** @brief Start the reference fixture.
 *
 * @sa https://example.com/first https://example.com/second
 *
 * @retval 0 If the fixture was started.
 */
int dpr_refs_start(void);

/** @brief Stop the reference fixture.
 *
 * @sa dpr_refs_start dpr_refs_restart
 *
 * @retval 0 If the fixture was stopped.
 */
int dpr_refs_stop(void);

/** @brief Restart the reference fixture.
 *
 * @sa dpr_refs_start()
 *
 * @retval 0 If the fixture was restarted.
 */
int dpr_refs_restart(void);

/** @brief Get the state of the reference fixture.
 *
 * The state is only valid after dpr_refs_start() has returned successfully.
 *
 * @return State of the fixture.
 */
int dpr_refs_state(void);

/** @brief Report of the reference fixture. */
struct dpr_refs_report {
	/** Number of restarts. */
	unsigned int restarts;
};

/** @brief Mode of the reference fixture. */
enum dpr_refs_mode {
	/** Fixture is idle. */
	DPR_REFS_MODE_IDLE,
};

/** @brief Fill a report of the reference fixture.
 *
 * The report is described by @ref dpr_refs_report and the mode by @ref dpr_refs_mode.
 *
 * @param[out] report Report to fill.
 *
 * @retval 0 If the report was filled.
 */
int dpr_refs_report_get(struct dpr_refs_report *report);

/** @} */
