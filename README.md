# drush-xhgui
XHGui integration with Drush.

# Installation
Add the following option via drushrc:

```php
$options['xhgui-header'] = '/path/to/xhgui/external/header.php';'
```

Once this has been added, simply add the `--xhgui` flag to any drush command to record the run.

# Composer Install
To install via composer add the following to your composer.json file

- Add `"lpeabody/drush-xhgui": "dev-master"` under `"require-dev"` to your `composer.json` file and run `composer update`.
