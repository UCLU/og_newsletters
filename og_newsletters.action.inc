<?php

/**
 * @file
 * og_newsletters.actions.inc
 */
function og_newsletters_email_members_action_form($context) {
  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Subject of the email'),
    '#required' => TRUE,
  );

  $form['body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#description' => t('Body of the email'),
    '#required' => TRUE,
    '#type' => 'text_format',
    '#format' => 'transactional_email',
  );

  return $form;
}

function og_newsletters_email_members_action_submit($form, $form_state) {
  $body_formatted = check_markup($form_state['values']['body']['value'], $form_state['values']['body']['format']);
  return array(
    'subject' => $form_state['values']['subject'],
    'body' => $body_formatted,
  );
}

/**
 * Action used in og_newsletters_action_info(). This will be available to VBO.
 */
function og_newsletters_email_members_action(&$account, $context = array()) {
  $to = $account->mail;
  $subject = $context['subject'];
  $body = $context['body'];

  og_newsletters_send_email($to, $subject, $body);
}

