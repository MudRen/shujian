// gongzige.c

inherit NPC;

void create()
{
        set_name("���Ӹ�", ({"gongzi ge","gongzi"}) );
        set("gender", "����" );
        set("age", 20);
        set("long", "����һ�����ֺ��еĹ��Ӹ磬һ��˭���Ʋ�������ӡ�\n");

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set("combat_exp", 123750);
	set("shen_type", -1);
        set("shen",-10);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", 2);
}
