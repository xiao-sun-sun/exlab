var express = require('express');
var router = express.Router();

/* GET api listing. */
router.get('/version', function(req, res, next) {
  res.send({ 'version': '1.0.0' });
});

router.get('/echo', function(req, res, next) {
  res.send({ 'name': req.query.name });
});

router.get('/sum', function(req, res, next) {
  // 从查询参数中获取两个数
  const a = parseInt(req.query.a);
  const b = parseInt(req.query.b);

  // 检查输入是否有效
  if (isNaN(a) || isNaN(b)) {
    return res.status(400).send({ error: 'Invalid input. Please provide valid numbers.' });
  }

  // 计算两数之和
  const sum = a + b;

  // 返回结果
  res.send({ 'sum': sum });
});

// 处理POST请求的路由
router.post('/sum', function(req, res) {
  const a = parseFloat(req.body.a);
  const b = parseFloat(req.body.b);
  // 检查输入是否有效
  if (isNaN(a) || isNaN(b)) {
    return res.status(400).send({ error: 'Invalid input. Please provide valid numbers.' });
  }

  // 计算两数之和
  const sum = a + b;

  // 返回结果
  res.send({ 'sum': sum });
});

module.exports = router;
