<?php

/**
 * @file
 * Handles the form validation of the customer survey form.
 *
 * All hooks are in the .module file.
 */

/**
 * Master validation function for the customer survey form.
 *
 * Uses per-stage validation and calls functions for each one.
 */
function customer_survey_form_validate($form, &$form_state) {
  if ($form_state['triggering_element']['#value'] == 'Back') {
    return;
  }

  switch ($form_state['stage']) {
    case 'rate_the_room':
      customer_survey_rate_the_room_validate($form, $form_state);
      break;

    case 'rate_the_service':
      customer_survey_rate_the_service_validate($form, $form_state);
      break;

    case 'personal_details':
      customer_survey_personal_details_validate($form, $form_state);
      break;
  }
}

/**
 * Validation for the rate_the_room step.
 */
function customer_survey_rate_the_room_validate($form, &$form_state) {
  if (!$form_state['values']['room_rating']) {
    form_set_error('room_rating', 'You must rate our room before continuing');
  }
}

/**
 * Validation for the rate_the_service step.
 */
function customer_survey_rate_the_service_validate($form, &$form_state) {
  if (!$form_state['values']['service_rating']) {
    form_set_error('service_rating', 'You must rate our service before continuing');
  }
}

/**
 * Validation for the personal_details step.
 */
function customer_survey_personal_details_validate($form, &$form_state) {
  if (!$form_state['values']['name']) {
    form_set_error('name', 'You must enter a name before continuing');
  }

  if (!valid_email_address($form_state['values']['email'])) {
    form_set_error('email', 'You must enter a valid email address');
  }
}
