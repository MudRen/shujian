// xiangnu.c

inherit NPC;

void create()
{
        set_name("��Ů",({ "xiang nu","xiang","nu" }) );
        set("gender", "Ů��" );
        set("age", 16);
        set("long", 
"����������һ��Ц�ۣ��������ֵĿ�����Χ����\n");

        set("str", 18);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("shen_type", 1);
//      set("shen", 100);
        set_temp("apply/defense", 10);
        set("combat_exp", 250);
        set("attitude", "peaceful");

        setup();

        carry_object(__DIR__"obj/cloth")->wear();
}