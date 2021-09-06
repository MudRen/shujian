// gushou.c ����

inherit NPC;

void create()
{
        set_name("�����ɹ���", ({ "gu shou", "gushou", "shou" }));
        set("long",
                "���������ɵĴ����֡�\n"
                "����ǰ����һֻͭ�ģ�һ����һ�߳���ɤ�ӳ�Щ����Ļ���\n");
        set("gender", "����");
        set("age", 43);
        set("attitude", "peaceful");
        set("shen", -200);
        set("str", 26);
        set("int", 16);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 400);
        set("max_jing", 400);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 10);
        set("combat_exp", 4000);

        set_skill("force", 40);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);

        setup();
        set("chat_chance", 2);
        add_money("coin", 50);
        set("chat_msg", ({
"��������ͭ�ģ��������������ǡ��ޡ��ϡ��ɣ�������御����\n",
"��������ͭ�ģ��������������ǡ��ޡ��ϡ��ɣ��¡��䡫�졫�ء���\n",
"��������ͭ�ģ��������������ǡ��ޡ��ϡ��ɣ��š����ޡ��ȡ���\n",
        }) );

        carry_object(BINGQI_D("tonggu"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}
