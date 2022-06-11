const {Router} = require('express');

const { sendAlert } = require('../controllers/alert');

const router = Router();

router.post('/send', sendAlert);

module.exports = router;