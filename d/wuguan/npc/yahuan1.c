//yahuan1.c
inherit NPC;

void create()
{
        set_name("Ѿ��", ({ "ya huan","ya","huan"}) );
        set("gender", "Ů��" );
        set("age", 20);
        set("long", "����һ��Ѿ������ò�������ס�\n");
        set("shen_type", 1);
        set("combat_exp", 1000);
        set("str", 18);
        set("dex", 18);
        set("con", 18);
        set("int", 19);
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 80);
} 