#include <ansi.h>
inherit NPC;
#define MIRROR_SYS "/quest/gmd/sys/mirror_sys"
int ask_job();

void create()
{

       set_name(HIG"���Դ�ʦ"NOR, ({ "kongxing dashi", "kongxing" ,"dashi"}));
set("title",HIR"�����Ĵ���ɮ"NOR);
         set("class", "bonze");
        set("gender", "����");
        set("age", 60);
        set("long","�������������Ĵ���ɮ���������ԡ�֮һ��
��ͨ������צ�֣�ƽ�ն������о����书����ɽ���١�\n");
        set("age", 70);
        set("shen", 32000);
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 12000);
        set("max_jing", 10000);
        set("eff_jingli", 9000);
        set("neili", 22000);
        set("max_neili", 22000);
        set("jiali", 150);
        set("combat_exp", 6400000);

        set_skill("force", 400);
        set_skill("yijin-jing", 400);
        set_skill("dodge", 400);
        set_skill("shaolin-shenfa", 400);
        set_skill("fumoquan-zhen", 200);
        set_skill("claw", 400);
        set_skill("parry", 400);
        set_skill("cuff", 400);
        set_skill("club", 400);
        set_skill("blade", 400);
        set_skill("ranmu-daofa", 400);
        set_skill("finger", 400);
        set_skill("strike", 400);
        set_skill("buddhism", 200);
        set_skill("riyue-bian", 400);
        set_skill("whip", 400);
        set_skill("yizhi-chan", 400);
        set_skill("literate", 250);
        set_skill("jingang-quan", 400);
        set_skill("hand", 400);
        set_skill("leg", 400);
        set_skill("ruying-suixingtui", 400);
        set_skill("banruo-zhang", 400);
        set_skill("qianye-shou", 400);
        set_skill("longzhua-gong", 400);
        set_skill("weituo-chu", 400);
        set_skill("zui-gun", 400);
        set_skill("club", 400);
        set_skill("nianhua-zhi",400);
        set_skill("xiuluo-dao",400);

        map_skill("blade","ranmu-daofa");
        map_skill("club","weituo-chu");
        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "yizhi-chan");
        map_skill("cuff","jingang-quan");
        map_skill("leg","ruying-suixingtui");
        map_skill("hand","qianye-shou");
        map_skill("claw","longzhua-gong");
        map_skill("whip","riyue-bian");
        map_skill("strike","banruo-zhang");
        prepare_skill("finger", "yizhi-chan");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "jingang" :),
                (: perform_action, "finger.qiankun" :),
                (: perform_action, "finger.wofo" :),
        }));
 create_family("������", 36, "����");
set("inquiry", ([ 
        	"��ɽ" : (: ask_job :),
            ])); 
carry_object("/d/shaolin/obj/xuan-cloth")->wear();
        setup();
}
int ask_job()
{
object me;
object *team;
object* ppl;
	int i,t,a,b,c,d,e;

me = this_player();
team = me->query_team();

if(!me->is_team_leader())
	{
		tell_object(me,"�㲻����ӡ�\n");
		return 1;
	}
for (i = 0;i < sizeof(team);i ++)
{
if (!team[i])
command("say ��Ķ�����������⣬���ɢ�������齨��\n");

                                       if (!present(team[i]))
                        command("say ��ô�����˲�ȫ����" + team[i]->query("name") + "��ôû����\n");
if (team[i]->query("family/family_name")!=me->query("family/family_name"))
{
command("knock "+ me->query("id"));

tell_object(me,"���ͬ�Ӷ��Ѳ���һ�����ɵġ�\n");
return 1;
}
}
ppl = users();
t = sizeof(ppl);
a=0;
b=0;
c=0;
d=0;
e=0;

while(t--){
	if(userp(ppl[t]) &&!wizardp(ppl[t]) && ppl[t]->query_temp("/quest/gmd/hongshui") )  a++;
			if(userp(ppl[t]) &&!wizardp(ppl[t]) && ppl[t]->query_temp("/quest/gmd/ruijin") )  b++;
					if(userp(ppl[t]) &&!wizardp(ppl[t]) && ppl[t]->query_temp("/quest/gmd/liehuo") )  c++;
							if(userp(ppl[t]) &&!wizardp(ppl[t]) && ppl[t]->query_temp("/quest/gmd/jumu") )  d++;
									if(userp(ppl[t]) &&!wizardp(ppl[t]) && ppl[t]->query_temp("/quest/gmd/houtu") )  e++;
		
		 }
if(a<1) {  team->set_temp("/quest/gmd/hongshui"); 
tell_object(me,""+me->query("family/family_name")+"��������������"HIW"��ˮ��"NOR"���룬ֱ������������������\n");
return 1;
}

	else if(b<1){ team->set_temp("/quest/gmd/ruijin");
tell_object(me,""+me->query("family/family_name")+"��������������"HIY"�����"NOR"���룬ֱ������������������\n");
return 1;
}

		else if(c<1) { team->set_temp("/quest/gmd/liehuo");
tell_object(me,""+me->query("family/family_name")+"��������������"HIR"�һ���"NOR"���룬ֱ������������������\n");
return 1;
}

			else if(d<1) { team->set_temp("/quest/gmd/jumu");
tell_object(me,""+me->query("family/family_name")+"��������������"HIG"��ľ��"NOR"���룬ֱ������������������\n");
return 1;
}

				else if(e<1) { team->set_temp("/quest/gmd/houtu");
tell_object(me,""+me->query("family/family_name")+"��������������"YEL"������"NOR"���룬ֱ������������������\n");
return 1;
}

	else 		{
tell_object(me,"�Ѿ��������㹻������ȥ�����������ˣ���ӭ�´β��롣\n");
return 1;}


}
