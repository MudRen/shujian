// shisong.c

inherit NPC;

void create()
{
	set_name("ʷ��", ({ "shi song","shi","song"}) );
        set("long","���ǳ�͢���٣�һ����װ��������\n");
        set("nickname", "������");
        set("gender", "����");
        set("age", 30);
        set("shen_type", -1);
        set("str", 24);
        set("int", 18);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 1200);
        set("max_jing", 1200);
        set("neili", 1200);
        set("max_neili", 1200);
        set("combat_exp", 220000);
        set_skill("force", 130);
        set_skill("qiantian-yiyang", 130);
        set_skill("dodge", 130);
        set_skill("xiaoyaoyou", 130);
        set_skill("parry", 130);
        set_skill("cihang-bian", 130);
        set_skill("whip", 130);
        set_skill("cuff", 130);
        set_skill("luohan-quan", 120);
        map_skill("cuff","luohan-quan");
        map_skill("force","qiantian-yiyang");
        map_skill("dodge","xiaoyaoyou");
        map_skill("whip","cihang-bian");
        map_skill("parry","cihang-bian");
        prepare_skill("cuff","luohan-quan");
	set_temp("apply/attack", 50);
        set_temp("apply/defense", 20);
        set("chat_chance", 10);
        set("chat_msg", ({
	"ʷ�ɴ����ȵ��������Ƿ���׽�ý�����éʮ�ˣ������˲�����ɣ����˿��� ������\n",
	"ʷ����¶�׹⣬˵���������ٱ������Ǵӱ������Ϸ�����Ϊ�ľ���׽����ػᷴ������\n",
	"ʷ��������һ��������������һ�ģ�˵���������¡������ޡ�ʷ�ɣ��������ٱ����������ػᷴ������\n",
       (: random_move :)
        }) );
        setup();
	carry_object(__DIR__"obj/armor")->wear();
	carry_object(__DIR__"obj/wbian")->wield();
}
