// yangguo.c ���

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

#include "xykm_job.h"
string ask_job();

void create()
{
	set_name("���",({"yang guo","yang"}));
	set("title",HIW"��Ĺ����"NOR);
	set("nickname",HIY"������"NOR);
	set("long", "�������������µ���������һ�۵����ڲ�ȥһ����Ӣ�ۺ�����\n");
	set("gender", "����");
	set("age", 39);
	set("attitude", "friendly");
	set("gender", "����");
	set("shen", 10000);
	set("per", 36);
	set("str", 40);
	set("int", 35);
	set("con", 40);
	set("dex", 35);

        set("max_qi", 10500);
        set("max_jing", 7000);
        set("neili", 18500);
        set("eff_jingli", 7500);
        set("max_neili", 18500);
        set("jiali", 150);
        set("combat_exp", 4800000);
        set("unique", 1);

        set_skill("sword",350);
        set_skill("dodge",350);
        set_skill("strike",350);
        set_skill("force", 350);
        set_skill("hand", 350);
        set_skill("cuff", 350);
        set_skill("parry", 350);
        set_skill("finger",140);
        set_skill("literate", 250);
        set_skill("xiantian-gong", 80);
        set_skill("hamagong",300);
        set_skill("medicine",120);
        set_skill("jingmai-xue", 80);
        set_skill("yunu-shenfa", 350);
        set_skill("xuantie-jianfa", 370);
        set_skill("anran-zhang", 380);
        set_skill("quanzhen-jianfa",360);
        set_skill("tianluo-diwang", 340);
        set_skill("yunu-xinjing",350);
        set_skill("jiuyin-zhengong",160);

        map_skill("force", "yunu-xinjing");        
        map_skill("sword","xuantie-jianfa");
        map_skill("dodge", "yunu-shenfa");
        map_skill("parry", "anran-zhang");        
        map_skill("hand", "tianluo-diwang");
        map_skill("strike", "anran-zhang");        
        prepare_skill("strike","anran-zhang");


	create_family("��Ĺ��",3,"������");

	set_temp("apply/damage", 70);
	set_temp("apply/dodge", 60);
	set_temp("apply/attack", 60);
	set_temp("apply/armor", 70);

	if (random(3))
		set("env/��������", "��ӿ");
        	setup();
	set("inquiry", ([
		"��Ĺ" : "���ջ�ɽ����Ӣ�۾��������������ڴ��������꣬�������£�����\n"+
			"�����ڴ˳���һ�����������ӣ�",
		"С��Ů" : "�������Ұ��ޣ�������������",
		"��������" : (: ask_job :),
                "job" : (: ask_job :),

	]));

        setup();
	carry_object(BINGQI_D("sword/gangjian"));
	carry_object("/d/gumu/obj/buxue1")->wear();
	carry_object("/d/gumu/obj/pao1")->wear();
}

string ask_job()
{
        object me = this_player();
        int exp = me->query("combat_exp");

        if( (int)me->query("shen") < 0 )
                return "�㾡�����£�����η��İ������ǰ�Σ�и����㡣\n";

        if( exp < 5000000 )
                return RANK_D->query_respect(me) + "���д��ģ��κ��书��Ϊ̫�\n";

        if( !wizardp(me) && me->query_condition("job_busy"))
                return "����������û��ʲô������Ȼ������ɡ�\n";

		   if(me->query_temp("quest/busy")) //added by tangfeng ��quest��ͻ
			    return "����������û�и���������㻹���ȴ����������������˵�ɡ�";

       if ( me->query_condition("killer"))
                 return "�������ǹٸ�׽�õ�Ҫ���������ȴ�������Լ��������!"; 
        if( me->query("menggu") )
                return "�ߣ����⺺�飬����Ҫ����\n";

        if( exp >5000000 ){
                return xykm_job();
        }
        return "������û��ʲô���Ը������������ˡ�\n";
}

void unconcious()
 {
         remove_all_killer();
         remove_all_enemy();
         say("������һ��: �о����裬��ɶ�����£���������\n");
         reincarnate();
         set("eff_qi", query("max_qi"));
         set("qi", query("max_qi"));
         set("eff_jing", query("max_jing"));
         set("jing", query("max_jing"));
         set("jingli", query("eff_jingli"));
         clear_conditions_by_type("poison");
 }
 
 void die()
 {
         unconcious();
 }