// haoshou.c ����

inherit NPC;

void create()
{
        set_name("�����ɺ���", ({ "hao shou", "haoshou", "shou" }));
        set("long",
                "���������ɵĴ����֡�\n"
                "����������һֻͭ�ţ�������������ش��š�\n");
        set("gender", "����");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen", -150);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 35);
        set_skill("parry", 30);

        setup();
        set("chat_chance", 2);

        set("chat_msg", ({
		"���ִ��˴�ͭ�ţ��������������ǡ��ޡ��ϡ��ɣ�������御����\n",
		"���ִ��˴�ͭ�ţ��������������ǡ��ޡ��ϡ��ɣ��¡��䡫�졫�ء���\n",
		"���ִ��˴�ͭ�ţ��������������ǡ��ޡ��ϡ��ɣ��š����ޡ��ȡ���\n",
        }) );
        carry_object(BINGQI_D("tonghao"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}
