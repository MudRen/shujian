// yayi.c  �ٸ�����
inherit NPC;

void create()
{
        set_name("����", ({ "pu ren", "a gen" }));
	set("gender", "����");
	set("age", 25);

        set("long", "һ������ˮ���������ˡ�\n");
        set("combat_exp", 500);
        set("shen_type", 0);
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
}
