inherit NPC;
void create()
{
        set_name("�ο�", ({ "you ke", "youke", "ke" }) );
	if(random(10)<6) set("gender","����");
        else set("gender","Ů��");
        set("age", 20+random(40));
        set("str", 16);
        set("per", 13+random(20));
        set("attitude", "peaceful");
	set("long", "����λ����������ο͡�\n");
        set("combat_exp", 3000+random(500));
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("force", 60);
        set_skill("literate", 60);
        set("chat_chance",5);
        set("chat_msg",({
                "�ο͵���������һƬɽ��ˮ�㣬���Ǹ��õط�����\n",
                (: random_move :),
                "�οͿ�����˵��������Ҳ������ɽ��ˮ�ģ������������ǽ����аɡ���\n",
                (: random_move :),
        }) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("coin", 10+random(20));
}
