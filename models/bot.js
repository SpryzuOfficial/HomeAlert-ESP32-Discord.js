const {Client, Intents} = require('discord.js');

class Bot
{
    constructor()
    {
        this.client = new Client({intents: [Intents.FLAGS.GUILDS, Intents.FLAGS.GUILD_MESSAGES]});
    }

    run()
    {
        this.client.on('ready', () =>
        {
            console.log(this.client.user.tag);
        });

        this.client.login(process.env.TOKEN);
    }
}

const bot = new Bot();

bot.run();

module.exports = bot;