#include <ansi.h>
inherit NPC;
string ask_baoming();
string* names = ({
"/d/hudong/xiangyang/defend",	"/d/hudong/xiangyang/attack",
});
void create()
{
        object ob;
        set_name("˵������", ({ "shuoshu laozhe", "shuoshu", "laozhe"}));
        set("gender", "����");
        set("unique", 1);
        set("age", 60);
        set("long", "����һ��˵�����ߣ�ר��˵Щ����֮�£���Ϊ���ʡ�\n");
        set("attitude", "friendly");
        set("shen", 150000);
        set("env/wimpy", 30);
        set("str", 19);
        set("int", 24);
        set("con", 22);
        set("dex", 26);

        set("max_qi", 4000);
        set("qi", 4000);
        set("jing",1600);
        set("eff_jing", 1600);
        set("jingli", 2200);
        set("eff_jingli", 2200);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 50);

        set("combat_exp", 1500000);
        
               set("chat_chance", 3);
        set("chat_msg", ({
            "˵���������������ƽ����ֿ��⾡�������Ʋ���ƶ���ɷ���¿�Х������֪��ȴͷ�Ͻ�......��\n",
            "˵�����ߵ�����������������Ӣ�������½̶��ܣ�������Ʒ��Ψ�ж����......��\n", 
        }) );

        set("inquiry", ([
           "����"  : (: ask_baoming :),
        ]));

        setup();
        if (clonep()) {
carry_object(ARMOR_D("changshan4"))->wear();
        add_money("gold",2);
   }
}

string ask_baoming()
{
object me = this_player();
int exp = me->query("combat_exp");
string objwhere;       
objwhere = names[random(sizeof(names))];


if( exp < 5000000 )
                return RANK_D->query_respect(me) + "���д��ģ��κ��书��Ϊ̫�\n";

        if( !wizardp(me) && me->query_condition("job_busy"))
                return "�������æʱ��δ�����Ȼ������ɡ�\n";

		   if(me->query_temp("quest/busy")) 
			    return "����������û�и���������㻹���ȴ����������������˵�ɡ�";

       if ( me->query_condition("killer"))
                 return "�������ǹٸ�׽�õ�Ҫ���������ȴ�������Լ��������!"; 
if(!this_object()->query("hd_start"))

return "������ս��û�п�ʼ���ȵȰ�!"; 


me->move(objwhere);
                return "ȥ�ɣ�\n";
}

