//yahuan.c
inherit NPC;

void create()
{
        set_name("Ѿ��", ({ "ya huan","ya","huan"}) );
        set("gender", "Ů��" );
        set("age", 14+random(3));
        set("long", "����һ��СѾ������ò�������ס�\n");
        set("shen_type", 1);
        set("combat_exp", 800);
        set("str", 18);
        set("dex", 18);
        set("con", 18);
        set("int", 19);
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 40);
} 