// tiao-fu.c ���� ��׼����npc, ��ת�Ƶ�NPC_D Ŀ¼��, lklv

inherit NPC;

void create()
{
	set_name("����", ({ "tiao fu", "tiaofu", "tiao", "fu", "porter" }) );
	set("gender", "����" );
	set("age", 20+random(15));
	set("long", "���Ǹ���ʵ�ͽ��������򣬳��ð�����Բ��һ���⡣\n");
	set("combat_exp", 20000 + random(400));
        set("str", 25);
        set("dex", 22);
        set("con", 20);
        set("int", 15);
	set("attitude", "heroism");

	setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
	add_money("silver", 3);
}
