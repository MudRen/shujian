// caidezhong.c ��ʽ�� tdh

inherit NPC;
#include "tdh_npc.h"

void create()
{
	set_name("��ʽ��", ({ "li shikai", "li", "shikai" }));
	set("gender", "����");
	set("age", 40);
	set("shen_type", 1);
	set("��ػ�/tangkou","�껯��");
	set("��ػ�/title","����");
	set("title", HIW"��ػ�껯������"NOR);
	set("long","��������ػ�껯����������С������˵�����ᡣ\n");

	set("str", 35);
	set("int", 25);
	set("con", 25);
	set("dex", 35);

	set("max_qi", 3600);
	set("max_jing", 1800);
	set("eff_jingli", 2200);
	set("neili", 6000);
	set("max_neili", 4400);
	set("jiali", 50);
	set("combat_exp", 2100000);

	set("no_get", 1);
	set("no_bark", 1);
	set("job_npc", 1);

	set_skill("cuff", 210);
	set_skill("strike", 210);
	set_skill("dodge", 210);
	set_skill("parry", 210);
	set_skill("force", 210);
	set_skill("taizu-quan", 210);
	set_skill("lianhua-zhang", 210);
	set_skill("xiantian-gong", 210);
	set_skill("shaolin-shenfa", 210);

	map_skill("force", "xiantian-gong");
	map_skill("cuff","taizu-quan");
	map_skill("strike","lianhua-zhang");
	map_skill("dodge","shaolin-shenfa");
	map_skill("parry","lianhua-zhang");
        random(3)>1 ? prepare_skill("cuff","taizu-quan"):prepare_skill("strike","lianhua-zhang");

	set("inquiry", ([
		"������": (: ask_join :),
		"��ػ�": (: ask_tdh :),
		"����": (: ask_tdh :),
		"���帴��": (: ask_fq :),
		"�½���": (: ask_chen :),
		"֣�ɹ�": (: ask_zheng :),
		"����ү": (: ask_zheng :),
		"�������ʫ": (: ask_sandian :),
		"�п�": (: ask_qk :),
		"����": (: ask_qk :),
		"�����巴ĸ�ظ���": (: ask_qk :),
		"�": (: ask_job :),
		"job": (: ask_job :),
		"����": (: ask_target :),
		"����": (: ask_fail :),
		"fangqi" : (: ask_fail :),
		"����" : (: ask_times :),
		"�������" : (: ask_times :),
		"rumors": "��˵������ӵ�צ���������������׽�ˡ�\n",
		"����": "����ʲô��\n",
		"���": "��ʲô�᣿�ҿɲ�����\n",
		"̨��": "��������˹���ү�������˺�ë���ո�̨�塣\n",
		"��͢": "��͢��Ҳ������ǰ�ĳ�͢�ˡ���\n",
		"����": "�������ʵ۶�Ӣ������ϧ���ﲻ�������������˴�ú�ɽ��\n",
		"����": "���ӱ�����ݶ���������ʮ�գ��ζ���������û��˵��?\n",
		"�ܶ���": "��˵������һ������\n",
		"��־��": "�Ǹ�����������Ҫ�������˱����ң�����Ҳ��������ɽ���ء�\n",
		"������": "�Ǹ��󺺼飬�Ѵ�ú�ɽ���������ӡ�����������һ�졭��\n",
		"����": "������٣������Ұ�����ͬ���ӻʵ�һ�����ˡ�\n",
		"��֮��": "������٣������Ұ�������ˡ�\n",
		"������": "�ǿ���һ����ѧ�߰�������ʶ��\n",
		"������": "�����Ǵ�����ѧ�ʰ��������ˣ��۱Ȳ��á�\n",
		"������": "�⡭��Ŷ�����Һ��񡭡�û��˵����\n",
		"ؤ��": "��˵��ػ������Ҳ�кܶ�ؤ����ֵܡ�\n",
		"��Ѫ��צ": "��˵���ܶ���������ôһ�Ź��򣬺���������\n",
	]));
	setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("silver", 10 + random(20));
}
