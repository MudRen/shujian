inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�ο�", ({ "you ke",  "ke" }) );
        if(random(10)<6) set("gender","����");
        else set("gender","Ů��");
        set("age", 20+random(40));
        set("str", 16);
        set("attitude", "peaceful");
        set("long", "����˿������ƺ�������ˡ�\n");
        set("combat_exp", 1000+random(500));
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("force", 60);
        set_skill("literate", 60);
        set("chat_chance",3);
        set("chat_msg",({
                CYN"�οʹ�е�����ù���浹ù��\n"NOR,
                CYN"�οͿ������ݺݵ�˵�����㣡С�ĵ㣡����û��ô�����˽ᣡ\n"NOR,
        }) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
	carry_object(BINGQI_D("gangjian"))->wield();
        add_money("silver", 10);
}
