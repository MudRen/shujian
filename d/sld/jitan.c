// jitan.c
// 3/3/2001  by emnil@sj

#include <ansi.h>

inherit ROOM;

void selectpfm(object);
string dopfm(object,int);
void pfmmsg(object);

void create()
{
        set("short", RED"��̳"NOR);
        set("long", 
HIW"��侲���ڹ���ʮ�ֻ谵��ֻ������ļ�̳�з������ĵĺ�⣬��
���ܳ�����һƬ�ڰ�֮�С���䷿��Ŀռ��ƺ������㾹Ȼ���ܿ���
���ܵı߼ʣ����������컨�塣���ƺ��Ѿ�����������һ��ʱ�ա�\n"NOR);

        set("exits", ([
                "out" : "/d/sld/pt",
        ]) );

        setup();
}


void init()
{
        add_action("do_canwu", ({"canwu"}));
        add_action("do_pfmmsg", ({"pfmmsg"}));
        add_action("do_wangque", ({"wangque"}));
        add_action("do_jidian", ({"jidian"}));
        add_action("selectpfm1", ({"pfmtype"}));
        add_action("selectpfm2", ({"pfmname"}));
}


int do_canwu(string arg)
{
        object me;
        int i;

        me = this_player();
        if ( me->is_busy() )
                return notify_fail("����æ���ء�\n");
        if ( me->query_skill("dulong-dafa",1)<256 )
                return notify_fail("�����Ϊ̫���ˣ����ܲ�����������ѧ��\n");
        if ( me->query("jing")<1000 )
                return notify_fail("��ľ���״̬̫���ˣ����ܲ�����������ѧ��\n");
        if ( me->query("max_neili")<3000 )
                return notify_fail("���������Ϊ̫���ˣ����ܲ�����������ѧ��\n");
        if ( me->query("neili")<2000 )
                return notify_fail("���������Ϊ̫���ˣ����ܲ�����������ѧ��\n");
        if ( (int)me->query("sld_pfm/lvl")>=5 )
                return notify_fail("�����Ϊ�Ѿ��ﵽ��߾��磬��Ҳ���򲻳�ʲô�ˡ�\n");
        i = time();
        if ( (i-(int)me->query("sld_pfm/ctime"))>3600 ) {
                me->set("sld_pfm/ctime",i);
                me->set("sld_pfm/ctimes",0);
        }
        else {
                if ( (int)me->query("sld_pfm/ctimes")>60 )
                        return notify_fail("��һ��ʼ���򣬾͸е����ҵ�ͷʹ������������������������ˡ�\n");
                else
                        me->add("sld_pfm/ctimes",1);
        }

        message_vision(HIW"$N��ϥ�����������ı���˫�ۣ��ƺ��Ѿ����������������ʱ�ա�\n"NOR,me);

        me->add("jing", -200-random(800));
        me->add("neili", -200-random(800));
        me->start_busy(100);
        call_out("canwu_over",15+random(30),me);

        return 1;
}

void canwu_over(object me)
{
        int i;

        me->add("potential",random(me->query_kar()));
        if ( (int)me->query("potential", 1) > (int)me->query("max_pot", 1) )
                me->set("potential" , me->query("max_pot", 1) );
        me->start_busy(1);

        switch ((int)me->query("sld_pfm/lvl")) {
                case 0: i=1; break;
		case 1: i=2; break;
                case 2: i=4; break;
                case 3: i=8; break;
                case 4: i=16; break;
        }
        if ( (int)me->query("sld_pfm/ccount") > (i*120*(40-me->query_kar())/20) ) {

                me->set("sld_pfm/ccount",0);
                switch ((int)me->query("sld_pfm/lvl")) {
                        case 0: 
                                message_vision(GRN"$N�����������۾���ͷ���л�Ȼ���ʣ��ƺ�������ʲô��\n"NOR,me);
                                selectpfm(me);
                                break;
                        case 1: 
                                message_vision(YEL"$N�����������۾���ͷ���л�Ȼ���ʣ���Ϊ�־�����һ�㣡\n"NOR,me);
                                me->set("sld_pfm/lvl",2);
                                me->add("sld_pfm/rate",10);
                                me->add("sld_pfm/neili_require",30);
                                me->add("sld_pfm/jingli_require",15);
                                me->add("sld_pfm/neilicost",30);
                                me->add("sld_pfm/jinglicost",15);
                                pfmmsg(me);
                                break;
                        case 2: 
                                message_vision(BLU"$N�����������۾���ͷ���л�Ȼ���ʣ���Ϊ�־�����һ�㣡\n"NOR,me);
                                me->set("sld_pfm/lvl",3);
                                me->add("sld_pfm/rate",15);
                                me->add("sld_pfm/neili_require",30);
                                me->add("sld_pfm/jingli_require",15);
                                me->add("sld_pfm/neilicost",30);
                                me->add("sld_pfm/jinglicost",15);
                                pfmmsg(me);
                                break;
                        case 3: 
                                message_vision(MAG"$N�����������۾���ͷ���л�Ȼ���ʣ���Ϊ�־�����һ�㣡\n"NOR,me);
                                me->set("sld_pfm/lvl",4);
                                me->add("sld_pfm/rate",15);
                                me->add("sld_pfm/neili_require",30);
                                me->add("sld_pfm/jingli_require",15);
                                me->add("sld_pfm/neilicost",30);
                                me->add("sld_pfm/jinglicost",15);
                                pfmmsg(me);
                                break;
                        case 4: 
                                message_vision(RED"$N�����������۾���ͷ���л�Ȼ���ʣ��ƺ���Ҫ������߾��磬ȴ�������˵�ʲô��

\n"NOR,me);
                                me->set("sld_pfm/clvl5",1);
                                break;
                }
        }
        else {
                message_vision(HIY"$N�����������۾����ƺ������ã����ƺ�һ������\n"NOR,me);
                me->add("sld_pfm/ccount",1);
        }
}

void selectpfm(object me)
{
        tell_object(me,"
��ѡ��������ľ������ࣺ
1.����          2.������        3.����������    4.��ǿ������
5.��ѧ������    6.����������    7.�ö���        8.�ϱ�����
9.����������ǿ������            10.���⹥����
���� pfmtype x ����ش����磺pfmtype 1����
");
        me->set_temp("sld/pfmtype",1);
}

int selectpfm1(string arg)
{
        int pfmtype;
        object me=this_player();

        if (!me->query_temp("sld/pfmtype")) 
                return 0;
        if ( (!arg) || (sscanf(arg,"%d",pfmtype)<1) || (pfmtype<1) || (pfmtype>10) )
                return notify_fail("����ȷѡ�����࣡\n");
        me->delete_temp("sld/pfmtype");

        tell_object(me,"��������������ľ��е�Ӣ����(�����������еľ��е�Ӣ������ͬ��������3~15֮��)��
���� pfmname xxx ����ش����磺pfmname yeah����\n");

        me->set_temp("sld/pfmname",1);
        me->set_temp("sld/pfmt",pfmtype);
        return 1;
}

int selectpfm2(string arg)
{
        int i,pfmtype;
        object me=this_player();

        if (!me->query_temp("sld/pfmname")) 
                return 0;
        i = strlen(arg);
        if ( (i<3) || (i>15) )
                return notify_fail("����ƾ���Ӣ�����ĳ��ȣ�\n");
        me->delete_temp("sld/pfmname");
        pfmtype = (int)me->query_temp("sld/pfmt");
        me->delete_temp("sld/pfmt");

        switch (pfmtype) {
                case 1:
                        pfmtype = 1;
                        break;
                case 2:
                        if ( random(2)==1 ) pfmtype=2; else pfmtype=12;
                        break;
                case 3:
                        if ( random(2)==1 ) pfmtype=3; else pfmtype=4;
                        break;
                case 4:
                        if ( random(2)==1 ) pfmtype=5; else pfmtype=6;
                        break;
                case 5:
                        if ( random(2)==1 ) pfmtype=7; else pfmtype=8;
                        break;
                case 6:
                        pfmtype=9;
                        break;
                case 7:
                        if ( random(2)==1 ) pfmtype=10; else pfmtype=11;
                        break;
                case 8:
                        pfmtype=16;
                        break;
                case 9:
                        pfmtype=14;
                        break;
                case 10:
                        if ( random(2)==1 ) pfmtype=13; else pfmtype=15;
                        break;
        }

        me->set("sld_pfm/neili_require",200);
        me->set("sld_pfm/jingli_require",150);
        me->set("sld_pfm/neilicost",100);
        me->set("sld_pfm/jinglicost",50);
        me->set("sld_pfm/weapon",1);
        me->set("sld_pfm/failbusy",2);
        me->set("sld_pfm/succesbusy",3);
        me->set("sld_pfm/rate",85);
        me->set("sld_pfm/diypfm",arg);
        me->set("sld_pfm/pfmtype",pfmtype);
        me->set("sld_pfm/lvl",1);
        me->add("max_neili",-10);

        me->set("sld_pfm/cdiypfm","δ����");
        me->set("sld_pfm/msg","δ����");
        me->set("sld_pfm/failmsg","δ����");
        me->set("sld_pfm/succesmsg","δ����");
        me->set("sld_pfm/succesmsg2","δ����");
        me->set("sld_pfm/endmsg","δ����");

        tell_object(me, "������� "+arg+" : "+dopfm(me,pfmtype)+"��\n");
        pfmmsg(me);
        return 1;
}

string dopfm(object me,int pfmtype)
{
        switch (pfmtype) {
                case 1:
                        me->set("sld_pfm/failbusy",3);
                        me->set("sld_pfm/bexp",1);
                        return "��";
                case 2:
                        me->set("sld_pfm/succes",1);
                        me->set("sld_pfm/succesbusy",4);
                        return "��������";
                case 3:
                        me->set("sld_pfm/succes",1);
                        return "�����Է�����";
                case 4:
                        me->set("sld_pfm/succes",1);
                        return "�����Է�����";
                case 5:
                        me->set("sld_pfm/succes",1);
                        return "��ǿ�������";
                case 6:
                        me->set("sld_pfm/succes",1);
                        return "��ǿ������";
                case 7:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        me->set("sld_pfm/neili_require",350);
                        return "��ѧ���������Է�����";
                case 8:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        me->set("sld_pfm/neili_require",350);
                        return "��ѧ���������Է�������������";
                case 9:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        me->set("sld_pfm/neili_require",120);
                        me->set("sld_pfm/rate",55);
                        return "�Ժ�����";
                case 10:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        return "�ö������Է��ľ�";
                case 11:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        return "�ö������Է�������������";
                case 12:
                        me->set("sld_pfm/succes",1);
                        me->set("sld_pfm/neili_require",300);
                        return "��ǿ�������������";
                case 13:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        me->set("sld_pfm/rate",150);
                        return "��ǿ�����ѧ����";
                case 14:
                        me->set("sld_pfm/succes",1);
                        return "��ǿ�������������������";
                case 15:
                        me->set("sld_pfm/succes",1);
                        me->set("sld_pfm/neili_require",300);
                        return "��ǿ�����������ڷ�������ǰ��һ��ʱ�������ܵ��˺��ӱ�";
                case 16:
                        me->set("sld_pfm/bskill1",1);
                        me->set("sld_pfm/skill1","force");
                        return "�϶Է�����";
        }
        return "�����pfm���";
}

void pfmmsg(object me)
{
        tell_object(me,"
����Ҫ�������²�����
cpfm:           ���е�������
msg:            ��������ʱ������
fmsg:           ����ʧ��ʱ������
smsg:           ���гɹ�ʱ����
smsg2:          �ڶ��γɹ�����
endmsg:         ���н���ʱ������

���÷�����pfmmsg ������ ����
���磺pfmmsg cpfm �������

�������Լ���ɫ��������nick��ͬ��
�����п�����$N�����Լ���$n������ˣ�
����������\n�����С�
");
}

int do_pfmmsg(string arg)
{
        string str1,str2;
        object me = this_player();

        if ((!stringp(arg)) || (sscanf(arg,"%s %s",str1,str2)<2))
                return notify_fail("�����ʽ��pfmmsg ������ ����\n");

        switch (str1) {
                case "cpfm":
                        me->set("sld_pfm/cdiypfm",str2);
                        break;
                case "msg":
                        me->set("sld_pfm/msg",str2);
                        break;
                case "fmsg":
                        me->set("sld_pfm/failmsg",str2);
                        break;
                case "smsg":
                        me->set("sld_pfm/succesmsg",str2);
                        break;
                case "smsg2":
                        me->set("sld_pfm/succesmsg2",str2);
                        break;
                case "endmsg":
                        me->set("sld_pfm/endmsg",str2);
                        break;
        }
        
        tell_object(me,"�������óɹ���\n");
        return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int do_wangque(string arg)
{
        object me = this_player();

        if ( (int)me->query("sld_pfm/lvl")<=0 )
                return notify_fail("�㲢û�в���ʲô���������ȴ�أ�\n");

        if ( !(int)me->query_temp("sld/wangque") ) {
                tell_object(me,"һ��ѡ����ȴ������ǰ�������Ͷ��ɶ��׷��ˣ��뿼�������\n"+
                               "�����ȷ��Ҫ��ȴ�����򵽵ľ�ѧ����������һ���������\n" );
                me->set_temp("sld/wangque",1);
        }
        else {
                me->delete_temp("sld/wangque");
                me->add("max_neili",-1);
                message_vision(HIR"$N��������˫�ۣ�����ڤ˼�����ã�ͻȻ���һ������Ȼ�����۾���\n˫�۵�Ѫ������͸���ޱ�ʹ���

���顣������\n"NOR,me);         

                me->delete("sld_pfm/diypfm");
                me->delete("sld_pfm/cdiypfm");
                me->delete("sld_pfm/neili_require");
                me->delete("sld_pfm/jingli_require");
                me->delete("sld_pfm/neilicost");
                me->delete("sld_pfm/jinglicost");
                me->delete("sld_pfm/weapon");
                me->delete("sld_pfm/msg");
                me->delete("sld_pfm/failmsg");
                me->delete("sld_pfm/succesmsg");
                me->delete("sld_pfm/succesmsg2");
                me->delete("sld_pfm/endmsg");
                me->delete("sld_pfm/failbusy");
                me->delete("sld_pfm/succesbusy");
                me->delete("sld_pfm/pfmtype");
                me->delete("sld_pfm/lvl");

                me->delete("sld_pfm/rate");
                me->delete("sld_pfm/succes");
                me->delete("sld_pfm/bjingli");
                me->delete("sld_pfm/bneili");
                me->delete("sld_pfm/bexp");
                me->delete("sld_pfm/bstr");
                me->delete("sld_pfm/bdex");
                me->delete("sld_pfm/bint");
                me->delete("sld_pfm/bkar");
                me->delete("sld_pfm/bskill1");
                me->delete("sld_pfm/bskill2");
                me->delete("sld_pfm/skill1");
                me->delete("sld_pfm/skill2");

                me->delete("sld_pfm/ctime");
                me->delete("sld_pfm/ctimes");
                me->delete("sld_pfm/ccount");
                me->delete("sld_pfm/clvl5");
        }

        return 1;
}

int do_jidian(string arg)
{
        object me,ob,env;

        me = this_player();
        if ( me->id(arg) )
                ob = me;
        else 
                ob = present(arg, me);

        if ( !ob )
                return notify_fail("��Ҫ��˭�������Լ�����ꣿ\n");
        if ( !(int)me->query("sld_pfm/clvl5") )
                return notify_fail("�㻹û�дﵽ��Ҫ����ľ��硣\n");
        if ( !userp(ob) )
                return notify_fail("�����������������Լ�����꣡\n");
        if ( ob->query("combat_exp")<100000 )
                return notify_fail("������������˵ľ�������̫���ˣ��޷�ȡ���κ��ջ�\n");

        if ( ob==me )
                message_vision(RED"$N���������̳����̳�����谵�Ļ��涸Ȼ����������Ĺ�â����$N��û��\n"NOR,me);
        else
                message_vision(RED"$N��$nͶ���̳����̳�����谵�Ļ��涸Ȼ����������Ĺ�â����$n��û��\n"NOR,me,ob);
        tell_object(me,RED"�������ͻȻ����һ����⣬����ǰ�������һ���ڻ��ͨ���������������ѧ����߾��磡\n"NOR);

        me->set("sld_pfm/lvl",5);
        me->delete("sld_pfm/clvl5");
        me->add("sld_pfm/rate",18);
        me->add("sld_pfm/neili_require",39);
        me->add("sld_pfm/jingli_require",20);
        me->add("sld_pfm/neilicost",39);
        me->add("sld_pfm/jinglicost",20);
        pfmmsg(me);

        env = environment(me);
        ob->set_temp("last_damage_from", "��������");
        ob->die();

        ob=present("corpse", env);
        if (ob)
		destruct(ob);

        return 1;
}
