<?php

/**
 * @file
 * Handles the form elements of the customer survey form
 * All hooks are in the .module file.
 */

/**
 * Master form which calls an individual form for each step.
 * 
 * @see customer_survey_form_validate().
 * @see customer_survey_form_submit().
 * 
 * @param type $form
 * @param string $form_state
 * @return type 
 */
function customer_survey_form($form, &$form_state) {
     
  drupal_add_css(drupal_get_path('module', 'customer_survey') . '/css/customer_survey.css');
  if (!isset($form_state['stage'])) $form_state['stage'] = 'rate_the_room';
 
  $form = array();
  $form = customer_survey_get_header($form, $form_state);

  switch ($form_state['stage']) {
    
    case 'rate_the_room':
      return customer_survey_rate_the_room_form($form, $form_state);
     break;  
 
    case 'rate_the_service': 
      return customer_survey_rate_the_service_form($form, $form_state);  
     break;
 
    case 'personal_details': 
      return customer_survey_personal_details_form($form, $form_state);  
     break;
 
    default:
      return customer_survey_rate_the_room_form($form, $form_state);
     break; 
  }
  
  return $form;
    
}


/**
 * Form for the rate_the_room step.
 * 
 * @see customer_survey_form().
 *  
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function customer_survey_rate_the_room_form($form, &$form_state) {
    
  $values = isset($form_state['multistep_values']['rate_the_room']) ? $form_state['multistep_values']['rate_the_room'] : array();

  $form['rate_the_room']['room_rating'] = array(
    '#type' => 'radios',
    '#title' => 'How would you rate the room you stayed in?',
    '#options' => array(1 => 1, 2 => 2, 3 => 3, 4 => 4, 5 => 5),
    '#default_value' => isset($values['room_rating']) ? $values['room_rating'] : NULL,
  );
  
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => t('Next')
  );
    
  return $form;
}


/**
 * Form for the rate_the_service step.
 * 
 * @see customer_survey_form().
 *  
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function customer_survey_rate_the_service_form($form, &$form_state) {
    
  $values = isset($form_state['multistep_values']['rate_the_service']) ? $form_state['multistep_values']['rate_the_service'] : array();

  $form['rate_the_service']['service_rating'] = array(
    '#type' => 'radios',
    '#title' => 'How would you rate our service?',
    '#options' => array(1 => 1, 2 => 2, 3 => 3, 4 => 4, 5 => 5),
    '#default_value' => isset($values['service_rating']) ? $values['service_rating'] : NULL,
  );
  
  $form['back'] = array(
    '#type' => 'submit',
    '#value' => t('Back')
  );
  
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => t('Next')
  );
    
  return $form;
}


/**
 * Form for the personal_details step.
 * 
 * @see customer_survey_form().
 *  
 * @param type $form
 * @param type $form_state
 * @return type 
 */
function customer_survey_personal_details_form($form, &$form_state) {

  $values = isset($form_state['multistep_values']['personal_details']) ? $form_state['multistep_values']['personal_details'] : array();

  $form['personal_details']['name'] = array(
    '#type' => 'textfield',
    '#title' => 'Name',
    '#default_value' => isset($values['name']) ? $values['name'] : NULL,
  );
  
  $form['personal_details']['email'] = array(
    '#type' => 'textfield',
    '#title' => 'Email',
    '#default_value' => isset($values['email']) ? $values['email'] : NULL,
  );
 
  $form['back'] = array(
    '#type' => 'submit',
    '#value' => t('Back')
  );
  
  $form['next'] = array(
    '#type' => 'submit',
    '#value' => t('Submit')
  );
  
  return $form;
}
