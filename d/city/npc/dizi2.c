// dizi2.c

inherit NPC;

void create()
{
        set_name("������ؤ", ({ "qi gai", "beggar" }) );
	set("gender", "����");
	set("age", 19);
	set("long", "����һ���������ؤ�����ϴ��ſ��ʵ�Ц�ݡ�\n");


	set("combat_exp", 1000);
	set("shen_type", 0);

	set("attitude", "peaceful");

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 10);

	setup();

}
