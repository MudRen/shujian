// laozu.c Ѫ������
// by iceland

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        object weapon;
        set_name("Ѫ������", ({ "xuedao laozu", "laozu","xuedaolaozu" }));
        set("long",@LONG
����ĸ��ݣ��������ݣ�һ˫�۾�����׺ݵĹ�â�����˲���ֱ�ӡ����ڽ���
���Բ��̺�ɫ�����ƣ���ƾһ��Ѫ�����Ĺ��򶷰�������ԭ�����ֺ��ܡ�
LONG
        );
        set("title", HIR "������Ѫ��������" NOR);
        set("gender", "����");
	set("class", "huanxi");
        set("age", 65);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 35);
        set("int", 30);
        set("con", 35);
        set("dex", 35);
        set("max_qi", 2100);
        set("eff_jing", 600);
	set("max_jing",600);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 30);
        set("combat_exp", 1000000);
        set("score", 500000);
	set("unique", 1);

        set_skill("huanxi-chan", 180);
        set_skill("literate", 150);
        set_skill("force", 180);
        set_skill("longxiang-boruo", 180);
        set_skill("dodge", 180);
        set_skill("yuxue-dunxing", 180);
        set_skill("claw", 180);
        set_skill("tianwang-zhua", 180);
        set_skill("hand", 180);
        set_skill("dashou-yin", 180);
        set_skill("blade",200);
        set_skill("xuedao-jing",200);
        set_skill("parry", 180 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xuedao-jing");
        map_skill("claw", "tianwang-zhua");
        map_skill("blade", "xuedao-jing");

        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");

        create_family("������", 10, "����");
        set("class", "huanxi");

        set("chat_chance", 2);
	set("chat_msg", ({
"Ѫ������̧��ͷ��������˼�����������������Բ�ˣ�����ɽɱ���˼������ˡ���\n",
"Ѫ������޺޵�˵����ʲôʱ��������ԭ�����ָ��췭�ظ�����\n",
"Ѫ������ҧ���гݣ���¶�׹��˵�����´�����ն�ݳ�����һ�����Ҳ��������\n",
"Ѫ���������������������ʹ��ˣ�������һ��Ҳ����������������Ϊ���⡣\n",
}) );
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "shield xuedao laozu" :),
                (: perform_action, "blade.shendao" :), }));

        setup();
        carry_object("/d/xueshan/npc/obj/longxiang-jiasha")->wear();
       if (clonep()){
           weapon = unew(BINGQI_D("xuedao"));
           if(!weapon)weapon=new(BINGQI_D("xinyuedao"));
            weapon->move(this_object());
           weapon->wield();
     }
        add_money("gold",5);
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name") != "������") {
                command("say"+ RANK_D->query_respect(ob) +
                        "���Ǳ��µ��ӣ������ﵷʲô�ң���");
                return;
        }

        if ((int)ob->query_skill("longxiang-boruo", 1) < 150) {
                command("say �Ҵ����¸����书�����ڹ��ศ��ɡ�");
                command("say"+ RANK_D->query_respect(ob) +
                        "�ٰ�����ͨ��������������б��ŵ��ķ��ɡ�");
                return;
        }

	if( (string)ob->query("gender") == "����" ) {
		command("say"+ RANK_D->query_respect(ob)+
                 "�����ȱ���������������\n");
                return;
        }
	if ((int)ob->query("shen") > -100000) {
		command("hmm");
		command("say ��Ѫ����������Զ���Щ��ν�Ľ��������ĸ�����������ӣ�");
		command("say �������ڵ��������������Ϊͽ�����»ᱻ�˳�Ц��");
		return;
        }
        command("say �����Ҿ�ϲ���������������ˡ��ã�������Ϊ�ҵ��Ӱɡ�");
        command("recruit " + ob->query("id"));

        ob->set("title", HIR "������Ѫ�������״�����" NOR);
}
