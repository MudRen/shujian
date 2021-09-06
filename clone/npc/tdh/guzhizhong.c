// guzhizhong.c ������ tdh

inherit NPC;
#include "tdh_npc.h"

void create()
{
	set_name("������", ({ "gu zhizhong", "gu", "zhizhong" }));
	set("gender", "����");
	set("age", 46);
	set("shen_type", 1);
	set("��ػ�/tangkou","�����");
	set("��ػ�/title","����");
	set("title", HIW"��ػ���������"NOR);
	set("long","������ػ�ĳ����������");

        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 22);
        set("max_qi", 2000);
        set("max_jing", 1400);
        set("max_jingli", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 1500000);

	set_skill("cuff", 200);
	set_skill("strike", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("force", 200);
	set_skill("taizu-quan", 200);
	set_skill("weituo-zhang", 200);
	set_skill("yijin-jing", 200);
	set_skill("shaolin-shenfa", 200);

	map_skill("force", "yijin-jing");
	map_skill("cuff","taizu-quan");
	map_skill("strike","weituo-zhang");
	map_skill("dodge","shaolin-shenfa");
	map_skill("parry","weituo-zhang");
        random(3)>1 ? prepare_skill("cuff","taizu-quan"):prepare_skill("strike","weituo-zhang");

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
		"����": "�Ǹ������ӣ������Ұ�����ͬ���ӻʵ�һ�����ˡ�\n",
		"��֮��": "�Ǹ����٣������Ұ�������ˡ�\n",
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
