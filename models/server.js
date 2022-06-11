const express = require('express');
const cors = require('cors');

class Server
{
    constructor()
    {
        this.app = express();

        this.paths = {alert: '/alert'}
        this.port = 8080;

        this.middlewares();
        this.routes();
    }

    middlewares()
    {
        this.app.use(cors());
        this.app.use(express.json());
    }

    routes()
    {
        this.app.use(this.paths.alert, require('../routes/alert'));
    }

    listen()
    {
        this.app.listen(this.port, () =>
        {
            console.log(`Server listening on port ${this.port}`);
        })
    }
}

module.exports = Server;