// shuren.c ˵����
//Creat by Looklove 2000/9/2

inherit NPC;

void create()
{
        set_name("˵����", ({ "shuoshu ren", "man", "ren" }));
	set("gender", "����");
        set("age", 42);
        set("long", "����һ����������־��ˮ䰴�������Ӣ�Ҵ��ȵ�Ӣ�۹��µ�˵���ˡ�\n");
	
        set("combat_exp", 1300);
        set("shen_type", 0);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
