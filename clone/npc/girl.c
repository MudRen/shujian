// nvhai.c

inherit NPC;

void create()
{
	set_name("Ů��",({"nv hai", "nvhai", "girl"}) );
        set("gender", "Ů��" );
        set("age", 16);
        set("long", "���Ǹ�ũ����Ů����Ȼֻ��ʮ�������꣬����Ѿ���ʼ������\n");
        set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
        set("str", 14);
        set("dex", 15);
        set("con", 16);
        set("int", 15);
        set("attitude", "peaceful");
        setup();
        carry_object(ARMOR_D("flower_shoe"))->wear();
        carry_object(ARMOR_D("pink_cloth"))->wear();
}