// Write By Yanyang@SJ 2001.9.27
// NPC: /d/changan/npc/shshren.c

inherit NPC;

void create()
{
        set_name("˵����", ({ "shuoshu ren", "ren"}) );
        set("gender", "����" );
        set("age", 45);
        set("long", "����һ����������־��ˮ䰴�������Ӣ�Ҵ��ȵ�Ӣ�۹��µ�˵���ˡ�\n");
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("per", 18);

        set("chat_chance", 5);
        set("chat_msg", ({
"˵���˶��������˼��ڲ�ˮ���ֿ�ʼ����˵�顣\n",
"˵���˽���ü��ɫ�衣\n",
"˵���˻�����ɫ�����ϲ�����˵���顣\n",
        }) );
        setup();
        carry_object(ARMOR_D("cloth.c"))->wear();
}