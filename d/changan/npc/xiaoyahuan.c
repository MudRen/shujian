// Write By Yanyang@SJ 2001.9.26
// NPC: /d/changan/npc/xiaoyahuan.c

inherit NPC;

void create()
{
        set_name("СѾ��", ({ "xiao yahuan", "yahuan"}) );
        set("gender", "Ů��" );
        set("age", 16);
        set("unique", 1);        
        set("long", "��λһ��������а��СѾ����\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("per", 30);

        set("chat_chance", 5);
        set("chat_msg", ({
"СѾ��˵��������������ߣ�������ұߡ���\n",
        }) );
        setup();
        carry_object(ARMOR_D("skirt1.c"))->wear();
}

int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 10000) 
        {
                tell_object(who, "СѾ��˵���������ȥϴϴ���ϵķ糾�ɣ���\n");
                who->set_temp("pay_wash",1);
                return 1;
        }
        return 0;
}
