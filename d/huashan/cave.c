// Room: /d/huashan/cave.c
// Date: Look 99/03/25
// Update by lsxk@hsbbs 2007/8/8  add huashan perform fengyi quest

#include <ansi.h>
string look_dazi();
inherit ROOM;
#include "fengyi5.h"
void create()
{
        set("short", "�ܶ�");
        set("long",@long
���߽���������ʯ�ں��棬���ж��죬�Ǹ����ݵ�ǧ��֮�ڵĴ󶴣�����
���߾ߺ��ǣ����������ԣ����Ծ��б��С�ɽ���ı��������ͻ��һ���ʯ��
����һ��ƽ̨����ʯ֮�¿���ʮ��������(dazi)��������Ѹ���ʯ�����տ�
ʱ��ֻ��һ���̵ֿ��������Ժ��ƺ�ɽ�����ڴˡ���һ��֮�Ե�ʯǽ(wall)֮
�Ͽ����������Σ�����һ�ƣ���˵Ҳ�������ٸ�����Ȼ��ʹ�����������ƽ�ʹ
�����εĽ�������Щ����֮�ԣ���Ȼ����һ���ּ�(ziji)���㲻���뿴(kan)
���д��Щʲô��
long);
        set("exits", ([
                "out" : __DIR__"rukou",
        ]));
	set("item_desc", ([
            	"dazi" :  (:look_dazi:),
            	"wall" : @TEXT

       o    | o      o    \ o      o      o     <o     <o>
    --^|\    ^|^  --v|^    v|v    |/v   \|X|    \|      |
       /\     >\    /<      >\    /<      >\    /<      >\

       o>     o      o      o      o      o      o      o
       \ __   x     </     <|>    </>    <\>    <)>     |\__
      /<      >\    /<      >\    /<      >\     >>     L



    A˵����Spiderii�������ԣ���
    B˵����Spiderii�����۸��ˣ���
    C˵����Spiderii��������
    D˵����Spiderii����С˵��ʱ�����ȥLN2 PK!��
    E˵����SpideriiǷǮ����!��
    ...
TEXT
        ]));
        set("no_fight", 1);
        setup();
}

void init()
{
    if(this_player()->query("quest/hsjf/fengyi4_fail")){
        add_action("do_yanjiu", "yanjiu");
        this_player()->set_temp("quest/huashan/fengyi_yanjiu",1);
    }
    if(this_player()->query("quest/hsjf/fengyi4")=="pass"
      &&this_player()->query("quest/hsjf/fengyi5")!="pass"
      &&(int)this_player()->query("quest/hsjf/fengyi5_fail")<5
      &&(int)this_player()->query("quest/hsjf/fengyi4_time")+86400<time()
      &&this_player()->query("quest/huashan")=="����"
      &&!this_player()->query("quest/hsjf/fy5/kill_killer_pass")
      &&(!this_player()->query("quest/hsjf/fy5")||this_player()->query("quest/hsjf/fy5/yanlian")!="pass"))
        {
            this_player()->set_temp("fengyi5_zhuomo",1);
            call_out("fengyi5_init",3,this_player());
        }

    add_action("do_kan", "kan");

    if(this_player()->query("quest/hsjf/fy5/chuaimo")
       &&this_player()->query("quest/hsjf/fy5/kill_killer_pass")
       &&this_player()->query("quest/hsjf/fy5/yanlian")=="pass")
        add_action("do_chuaimo", "chuaimo");
}

int do_chuaimo(string arg)
{
    object me = this_player();

    if(!arg)
        return notify_fail("��Ҫ��Ħʲô��\n");

    if(arg!="�з�����" && arg!="����")
        return notify_fail("��Ҫ��Ħʲô��\n");

    if((int)me->query("quest/hsjf/fengyi5_fail")>=5){
        me->delete("quest/hsjf/fy5");
        return notify_fail(HIR"�������ʯ���ϵĽ��У���Ħ����Ħȥ�������޷�Ū����������Ⱳ��ҪŪ������ƺ��е㳬�����������Χ�ˡ�����\n"NOR);
    }

    if(QUEST_D->questing(me,27,5,"KAR")){
        write(HIG"�������ʯ���ϵĽ��У�������ղ����������ʹ�õ�������ͻȻ�������\n"+
                 "�⡰�з����ǡ������һ�У��㲻��������Ц����������~��ԭ����˰�!��\n"NOR);

        me->set("quest/hsjf/fengyi5","pass");
        me->delete("quest/hsjf/fy5");
        log_file("quest/fengyi5", sprintf(HIG"�з�����5Quest��¼��%s(%s)�ڻ�ɽ�ض�ʧ��%d�κ�"HIW"��Ħ"HIG"�ɹ�������%d��"NOR, me->name(1),me->query("id"), me->query("quest/hsjf/fengyi5_fail"), me->query("combat_exp")) );
        return 1;
    }
    write(HIY"�������ʯ���ϵĽ��У�������Ħ�ղ�������˵Ľ��У���Ȼ�����е�˼·���������޷����͸����\n"NOR);
    me->add("quest/hsjf/fengyi5_fail",1);
    log_file("quest/fengyi5", sprintf(HIR"�з�����5Quest��¼��%s(%s)�ڻ�ɽ�ض�"HIW"��Ħ"HIR"ʧ��%d�Ρ�����%d��"NOR, me->name(1),me->query("id"),me->query("quest/hsjf/fengyi5_fail"), me->query("combat_exp")) );

    return 1;
}

int fengyi5_init(object me)
{
    if(file_name(environment(me))!="/d/huashan/cave"
      &&file_name(environment(me))!="/u/lsxk/partyskill/newhs/quest/cave")
         return 1;

        write(HIY"��ʵ����Σ�������ּ�������ʯ��֮�����̵ġ�"HIC"�з�����"HIY"�����ƽ�\n"+
              "�������������������Ĳ����ƽ�һ�������������Ǳ��ŵ����С�"HIC"��\n"+
              "������"HIY"����\n"+
            HIR"\n��ֻ�������С�"HIC"�з�����"HIR"���������������ƺ������ϳ˵ĺ��н�����\n"+
              "���㲻����ʼ������ĥ����......\n\n"NOR);
        add_action("do_zhuomo","zhuomo");
        add_action("do_zhuomo","��ĥ");
    return 1;
}

int do_zhuomo(string arg)
{

    object me = this_player();

    if(!me->query_temp("fengyi5_zhuomo"))
        return notify_fail("��Ϲ��ĥɶ�أ��ø�ɶ��ɶȥ��\n");

    if(me->is_fighting()||me->is_busy())
        return notify_fail("����æ���أ�\n");

    if(!arg) return notify_fail("��Ҫ��ĥʲô��\n");

    if(arg!="�з�����")
        return notify_fail("��Ϲ��ĥɶ�أ�\n");

    if((int)me->query_skill("huashan-jianfa",1)<300)
        return notify_fail("��Ļ�ɽ����ʵ��̫��,Ϲ��ĥ�˰��컹�Ƿ�����!\n");

    if(me->query("quest/hsjf/fengyi5")=="pass")
        return notify_fail("��ô�ţ������Դ������У�\n"NOR);

    if((int)me->query("quest/hsjf/fengyi5_fail")>=5)
        return notify_fail("���ѽʾ���֭,����Ȼδ��,ֻ���½�����Ҳ�޷���͸�����а����ˣ�\n"NOR);

    fengyi5_zhuomo(me);

    return 1;
}

string look_dazi()
{

       return "ÿ�ĸ���һ�ţ�һ�����ţ�ÿ���ֶ��г������������ɽʯ��\n"
              "���ü������ı��п��룬������硣ʮ������������䣬���н�������̬֮��\n"

        "\n"
          "      ����������������������������������\n"
          "      ����������������������������������\n"
          "      �����������塡���������ɡ���������\n"
          "      �����������ޡ��ܡ��¡�������������\n"
          "      �����������ȡ��䡡����ʤ����������\n"
          "      ���������������㡡�����ˡ���������\n"
          "      ����������������������������������\n"
          "      ����������������������������������\n"
          "      ����������������������������������\n";
}

int do_kan(string arg)
{
    object me = this_player();

    if(me->is_fighting()||me->is_busy())
        return notify_fail("����æ���أ�\n");

    if (!arg || (arg != "ziji" && arg != "�ּ�") ) return notify_fail("���뿴ʲô��\n");

    if(me->query("quest/hsjf/fengyi4")=="pass")
        return notify_fail("��΢΢һЦ���ĵ�����Ҫ�������ƻ�ɽ�������������ڵ��죡\n");

    if(me->query("quest/hsjf/fengyi4_fail"))
        return notify_fail("��Щ�ּ����������������У��˿���ֻ���о������֮����\n");

    if(me->query("quest/huashan")!="����" || !me->query_temp("mb")) return notify_fail("����ǰ�������ۣ�û������ɶ����Ķ�������ʱ�����˰��죡\n");

    tell_object(me,HIY"������ǰȥ������һ������������ʮ�������֣�\n\n"NOR);
    tell_object(me,HIR"                     ����\n"+
                      "                     �˳�\n"+
                      "                     �Ʒ�\n"+
                      "                      ��\n"+
                      "                      ��\n"+
                      "                      ��\n"+
                      "                      ɽ\n"+
                      "                      ��\n"+
                      "                      ��\n"+
                      "                      !\n"NOR);

    call_out("fengyi_quest1",2,me);
    return 1;
}

int fengyi_quest1(object me)
{
    if(file_name(environment(me))!="/d/huashan/cave"
      &&file_name(environment(me))!="/u/lsxk/partyskill/newhs/quest/cave") 
         return 1;

    if(me->is_fighting()||me->is_busy())
        return notify_fail("����æ���أ�\n");

    write(HIW"�㲻����Ȼ��ŭ���ĵ������޳��󱲣��󵨿����Ѽ�����ɽ������΢�����\n"+
             "���ܵ���ס������ָ��������˭����˵����һ�����ơ��֣�����˭����˵�ǡ�\n"+
             "���ơ�����\n"NOR);

    call_out("fengyi_temp",5,me);
    return 1;
}

int fengyi_temp(object me)
{
    if(file_name(environment(me))!="/d/huashan/cave"
      &&file_name(environment(me))!="/u/lsxk/partyskill/newhs/quest/cave") 
         return 1;

    write(HIC"\n����һ����,����˴�ʯ�����Ǽ�Ӳ��Ҫ����ʯ���ϻ�ͼд�֣�����������Ҳ��ʮ�ֲ�\n"
    "��!�����ٴ�ϸ�Ĳ쿴ʯ��������ͼ��,��֪Խ��Խ���ľ�,ʹ��������ֻ�ݲ����ʣ���\n"
    "����Ϊ��ª����������֮�п������ף������ǻ�ɽ���������Ʒ������������ӯ�鶯,\n"
    "��֮�Բ���������г��ŵ���һ��ֱ���εı��У���֪���ǰ�������ǹì���ۼ�ʹ����\n"
    "�εĹ�����������֮�������ǻ�ɽ�����Ŀ���,������Ƶľ��޻���֮������ʱ�䣬��\n"
    "���ɶԱ����书����ȫʧ��\n\n"NOR);

    call_out("fengyi_temp2",2,me);
    return 1;
}

int fengyi_temp2(object me)
{
    if(file_name(environment(me))!="/d/huashan/cave"
      &&file_name(environment(me))!="/u/lsxk/partyskill/newhs/quest/cave")
         return 1;

    write(HIM"�����´�,�ѵ����ɴ��������书���е�����˲���,���˸���������ȥ?\n"
             "�㲻����Ҫ�о���͸�����⻪ɽ�����ѵ������˲���һ������\n\n"NOR);

    me->set_temp("quest/huashan/fengyi_yanjiu",1);
    add_action("do_yanjiu", "yanjiu");

    return 1;
}

int do_yanjiu(string arg)
{
    object me = this_player();
    int i;

    if(!me) return 0;

    if(!me->query_temp("quest/huashan/fengyi_yanjiu"))
        return notify_fail("�㻹�п��о����������ר�������Լ�����ȥ��\n");

    if(me->is_fighting()||me->is_busy())
        return notify_fail("����æ���أ�\n");

    if(!arg) return notify_fail("��Ҫ�о�ʲô��\n");

    if(arg!="���� at ʯ��")
        return notify_fail("��Ҫ�о�����Ķ�����\n");

    if((int)me->query_skill("huashan-jianfa",1)<230)
        return notify_fail("��Ļ�ɽ����ʵ��̫��,������ʯ���ϵľ����!\n");

    if(me->query("quest/hsjf/fengyi4")=="pass")
        return notify_fail("���Ѿ���͸���з����ǡ��ĵ��ĺ�����!\n"NOR);

    if((int)me->query("quest/hsjf/fengyi4_time")+86400 > time())
        return notify_fail("��ող��о������У���������Ϣ�°ɣ�\n");

    if((int)me->query_temp("quest/huashan/fengyi_yanjiu")<5){
        i = (int)me->query_skill("huashan-jianfa",1);
        i = i*i/7;
        me->add_temp("quest/huashan/fengyi_yanjiu",1);
        me->add("jingli",-(int)me->query("eff_jingli")/5);
        me->add("jing",-500);
        me->add("neili",-600);
        me->add_busy(3+random(3));
               me->improve_skill("huashan-jianfa",i);
        return notify_fail("����ϸ���о���ʯ���ϵĽ��У��������������ʧ���Ѿã����о�����ף�\n");
    }
    if(random((int)me->query_temp("quest/huashan/fengyi_yanjiu")+1)<5){
        if((int)me->query_temp("quest/huashan/fengyi_yanjiu")>=6){
            me->start_busy(2);
            me->add("quest/hsjf/fengyi4_fail",1);
            me->set("quest/hsjf/fengyi4_time",time());
            me->set("quest/hsjf/fengyi4_exp",me->query("combat_exp"));
            me->delete_temp("quest/huashan/fengyi_yanjiu");
            log_file("quest/fengyi", sprintf(HIR"�з�����Quest��¼��%s(%s)�ڻ�ɽ�ض�δ�����ĺ��С�����%d��"NOR, me->name(1),me->query("id"), me->query("combat_exp")) );
            return notify_fail(HIR"���˺þã�������Լ��Ļ�ɽ�������軹��̫�ͣ��޷����ʯ���ϵľ������У�\n"NOR);
        }
        i = (int)me->query_skill("huashan-jianfa",1);
        i = i*i/7;
        me->add_temp("quest/huashan/fengyi_yanjiu",1);
        me->add("jingli",-(int)me->query("eff_jingli")/5);
        me->add("jing",-500);
        me->add("neili",-600);
        me->add_busy(3+random(3));
        
        me->improve_skill("huashan-jianfa",i/2);
        return notify_fail("����ϸ˼�������ã����ֶԻ�ɽ��������ʶ�ֽ���һ����\n");
    }
    else{
            me->set("quest/hsjf/fengyi4","pass");
            me->set("quest/hsjf/fengyi4_exp",me->query("combat_exp"));
            me->set("quest/hsjf/fengyi4_time",time());
            me->delete_temp("quest/huashan/fengyi_yanjiu");
            me->start_busy(2+random(2));
            write(HIC"\n��ͻȻ��ʯ���Ϸ����ˡ��з����ǡ���һ�У���֪���н����˲�������У�����δ��͸��\n"+
                       "�����к͵����С�������ʯ����ʹ��֮�ˣ�������ӯ�鶯��������Ϊ�Źֵ�ȴ�����ޱȡ�\n"+
                  HIR"\n���£���ͻȻ���򵽣����������ģ���ȴ�ǻ�ģ���ɽ���������뽣��֮����νӱ仯��\n"+
                       "��һ�㲻��ģ���������ߣ����Ķ�����������Ȼ�νӵ������޷죬������ϳɵĻ�ɽ��\n"+
                       "������\n"+
                  HIY"\n�����򵽴ˣ��������ǡ����ơ����֣��������ƽ���֮�˸е���Ц�¼�!\n"NOR);
            log_file("quest/fengyi", sprintf(HIG"�з�����Quest��¼��%s(%s)�ڻ�ɽ�ض��ɹ������ĺ��С�����%d��"NOR, me->name(1),me->query("id"), me->query("combat_exp")) );
            return 1;
    }
}
