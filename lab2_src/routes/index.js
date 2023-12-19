var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

// 处理 /sum 路由
router.get('/sum', function(req, res) {
  res.render('sum');
});

module.exports = router;
