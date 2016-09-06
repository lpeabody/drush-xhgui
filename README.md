# drush-xhgui
XHGui integration with Drush.

# Installation
Add the following option via drushrc:

```php
$options['xhgui-header'] = '/path/to/xhgui/external/header.php';'
```

Once this has been added, simply add the `--xhgui` flag to any drush command to record the run.
