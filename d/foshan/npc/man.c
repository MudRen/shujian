//man.c by zly

inherit NPC;

void create()
{
        set_name("���", ({ "xiang ke","xiang","ke" }) );
        set("gender", "����" );
        set("age", 22+random(30));
        set("long", "������������һ���㣬�ϵĹ��ڷ������ǰ��\n");
        set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 100);
        set("max_neili", 100);
        set("combat_exp", 2000+random(1000));

        setup();
        add_money("silver", 5+random(10));
}

