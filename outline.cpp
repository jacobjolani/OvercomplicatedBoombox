
Below is a set of useful functions from GPIOD.H file to control a gpio pin. 
I have them roughly in the order they should be used. 

/**
 * @brief Open a chip by path.
 * @param path Path to the gpiochip device file.
 * @return GPIO chip object or NULL if an error occurred. The returned object
 *         must be closed by the caller using ::gpiod_chip_close.
 */
struct gpiod_chip *gpiod_chip_open(const char *path);

CHECK FOR NULL

/**
 * @brief Close the chip and release all associated resources.
 * @param chip Chip to close.
 */
void gpiod_chip_close(struct gpiod_chip *chip);

/**
 * @brief Create a new line settings object.
 * @return New line settings object or NULL on error. The returned object must
 *         be freed by the caller using ::gpiod_line_settings_free.
 */
struct gpiod_line_settings *gpiod_line_settings_new(void);

CHECK FOR NULL 

/**
 * @brief Free the line settings object and release all associated resources.
 * @param settings Line settings object.
 */
void gpiod_line_settings_free(struct gpiod_line_settings *settings);

/**
 * @brief Set direction.
 * @param settings Line settings object.
 * @param direction New direction.
 * @return 0 on success, -1 on error.
 */
int gpiod_line_settings_set_direction(struct gpiod_line_settings *settings,
				      enum gpiod_line_direction direction);

CHECK FOR -1
                      
/**
 * @brief Create a new line config object.
 * @return New line config object or NULL on error. The returned object must
 *         be freed by the caller using ::gpiod_line_config_free.
 */
struct gpiod_line_config *gpiod_line_config_new(void);

CHECK FOR NULL 
/**
 * @brief Free the request config object and release all associated resources.
 * @param config Line config object.
 */
void gpiod_request_config_free(struct gpiod_request_config *config);


/**
 * @brief Add line settings for a set of offsets.
 * @param config Line config object.
 * @param offsets Array of offsets for which to apply the settings.
 * @param num_offsets Number of offsets stored in the offsets array.
 * @param settings Line settings to apply.
 * @return 0 on success, -1 on failure.
 */
int gpiod_line_config_add_line_settings(struct gpiod_line_config *config,
					const unsigned int *offsets,
					size_t num_offsets,
					struct gpiod_line_settings *settings);

CHECK FOR -1

/**
 * @brief Request a set of lines for exclusive usage.
 * @param chip GPIO chip object.
 * @param req_cfg Request config object. Can be NULL for default settings.
 * @param line_cfg Line config object.
 * @return New line request object or NULL if an error occurred. The request
 *         must be released by the caller using ::gpiod_line_request_release.
 */
struct gpiod_line_request *gpiod_chip_request_lines(struct gpiod_chip *chip,
			 struct gpiod_request_config *req_cfg,
			 struct gpiod_line_config *line_cfg);

CHECK FOR NULL

/**
 * @brief Release the requested lines and free all associated resources.
 * @param request Line request object to release.
 */
void gpiod_line_request_release(struct gpiod_line_request *request);

/**
 * @brief Set the value of a single requested line.
 * @param request Line request object.
 * @param offset The offset of the line for which the value should be set.
 * @param value Value to set.
 * @return 0 on success, -1 on failure.
 */
int gpiod_line_request_set_value(struct gpiod_line_request *request,
				 unsigned int offset,
				 enum gpiod_line_value value);

CHECK FOR -1
