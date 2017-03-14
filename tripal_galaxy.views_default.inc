<?php

/**
 * @file
 * Describes default views
 */

/**
 * Describes default views
 *
 */
function tripal_galaxy_views_default_views() {
  $views = array();

  $view = tripal_galaxy_views_job_queue();
  $views[$view->name] = $view;

  return $views;
}


/**
 * Describes the jobs administration view.
 *
 * @ingroup tripal
 */
function tripal_galaxy_views_job_queue() {
  $view = new view();
  $view->name = 'galaxy_usage';
  $view->description = 'The Galaxy job queue';
  $view->tag = 'galaxy,job queue';
  $view->base_table = 'tripal_galaxy_workflow';
  $view->human_name = 'Galaxy Job Queue';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Galaxy Job Queue';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer galaxy';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'servername' => 'servername',
    'uid' => 'uid',
    'name' => 'name',
    'submit_date' => 'submit_date',
    'start_time' => 'start_time',
    'end_time' => 'end_time',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'servername' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'submit_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'start_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'end_time' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No jobs found';
  /* Relationship: Galaxy Workflow Submission: Submission ID */
  $handler->display->display_options['relationships']['sid']['id'] = 'sid';
  $handler->display->display_options['relationships']['sid']['table'] = 'tripal_galaxy_workflow_submission';
  $handler->display->display_options['relationships']['sid']['field'] = 'sid';
  $handler->display->display_options['relationships']['sid']['label'] = 'The webform submission.';
  /* Relationship: Webform submissions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'sid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'sid';
  $handler->display->display_options['fields']['title']['label'] = 'Workflow';
  /* Field: Galaxy Server: Server Name */
  $handler->display->display_options['fields']['servername']['id'] = 'servername';
  $handler->display->display_options['fields']['servername']['table'] = 'tripal_galaxy';
  $handler->display->display_options['fields']['servername']['field'] = 'servername';
  $handler->display->display_options['fields']['servername']['label'] = 'Galaxy Server';
  /* Field: Webform submissions: User */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'webform_submissions';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'sid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  /* Field: Galaxy Workflow Submission: Submission Time */
  $handler->display->display_options['fields']['submit_date']['id'] = 'submit_date';
  $handler->display->display_options['fields']['submit_date']['table'] = 'tripal_galaxy_workflow_submission';
  $handler->display->display_options['fields']['submit_date']['field'] = 'submit_date';
  $handler->display->display_options['fields']['submit_date']['date_format'] = 'short';
  $handler->display->display_options['fields']['submit_date']['second_date_format'] = 'long';
  /* Field: Galaxy Workflow Submission: Start Time */
  $handler->display->display_options['fields']['start_time']['id'] = 'start_time';
  $handler->display->display_options['fields']['start_time']['table'] = 'tripal_galaxy_workflow_submission';
  $handler->display->display_options['fields']['start_time']['field'] = 'start_time';
  $handler->display->display_options['fields']['start_time']['date_format'] = 'short';
  $handler->display->display_options['fields']['start_time']['second_date_format'] = 'long';
  /* Field: Galaxy Workflow Submission: End Time */
  $handler->display->display_options['fields']['end_time']['id'] = 'end_time';
  $handler->display->display_options['fields']['end_time']['table'] = 'tripal_galaxy_workflow_submission';
  $handler->display->display_options['fields']['end_time']['field'] = 'end_time';
  $handler->display->display_options['fields']['end_time']['date_format'] = 'short';
  $handler->display->display_options['fields']['end_time']['second_date_format'] = 'long';
  /* Field: Galaxy Workflow Submission: Submission Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'tripal_galaxy_workflow_submission';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Sort criterion: Galaxy Workflow Submission: Submission Time */
  $handler->display->display_options['sorts']['submit_date']['id'] = 'submit_date';
  $handler->display->display_options['sorts']['submit_date']['table'] = 'tripal_galaxy_workflow_submission';
  $handler->display->display_options['sorts']['submit_date']['field'] = 'submit_date';
  $handler->display->display_options['sorts']['submit_date']['order'] = 'DESC';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'sid';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Workflow';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['group'] = 1;
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'User';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Galaxy Workflow Submission: Submission Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'tripal_galaxy_workflow_submission';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Submission Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Galaxy Job Queue */
  $handler = $view->new_display('page', 'Galaxy Job Queue', 'galaxy_job_queue');
  $handler->display->display_options['path'] = 'admin/tripal/extension/galaxy/job-queue';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Job Queue';
  $handler->display->display_options['menu']['description'] = 'The Galaxy Job Queue';
  $handler->display->display_options['menu']['weight'] = '15';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  return $view;
}