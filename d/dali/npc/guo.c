// guo.c ����֮
inherit NPC;

void create()
{
        set_name("����֮", ({ "guo yanzhi","guo","yanzhi"}) );
        set("long","һ����ĸߴ�����꺺�ӣ�һ��ɥ����ͷ�����ڣ������糾֮ɫ��
��˫Ŀ���ף����Ǽ���ɥ�¡��������ˡ�\n");
        set("title","������");
        set("nickname", "׷���");
        set("gender", "����");
        set("age", 45);
        set("shen_type", -1);
        set("str", 27);
        set("int", 18);
        set("con", 22);
        set("dex", 24);
        set("unique", 1);

        set("max_qi", 1000);
        set("max_jing", 700);
        set("neili", 1000);
        set("max_neili", 1000);
        set("combat_exp", 450000);
        set("eff_jingli",700);
        set_skill("force", 100);
        set_skill("huntian-qigong", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 80);
        set_skill("whip",120);
        set_skill("parry", 100);
        map_skill("force", "huntian-qigong");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 20);
        set("chat_chance", 3);
        set("chat_msg", ({
        "����֮��������ʦ�����˺����������ǹ���Ľ�ݸɵģ��øϿ�ȥ�Ҵ�ʦ�ֹ��̱���֮�ơ�\n",
               (: random_move :)
        }) );
        setup();
        carry_object("/clone/armor/armor")->wear();
        carry_object(__DIR__"obj/bian")->wield();
}
