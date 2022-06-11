const {MessageEmbed, MessageActionRow, MessageButton} = require('discord.js');

const bot = require('../models/bot');

const sendAlert = async(req, res) =>
{
    const channel = await bot.client.channels.fetch(process.env.CH);

    const embed = new MessageEmbed()
                .setColor('#FF0000')
                .setTitle('INTRUDER ALERT')
                .setDescription('Alert')
                .setTimestamp();

    await channel.send({content:`<@!${process.env.ID}>`, embeds: [embed]});

    res.json({ok: true, msg: 'Alert sended'});
}

module.exports = {sendAlert};