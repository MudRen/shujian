// boy.c

inherit NPC;

void create()
{
        set_name("�к�",({ "boy" , "nanhai"}) );
        set("gender", "����" );
        set("age", 14);
        set("long", "������ݰ��ڼҵ�С����\n");
        set("combat_exp", 230);
 
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 20);
}
