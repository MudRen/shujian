// credit_box.c  ͨ����  By lsxk@hsbbs 2007/7/19 ��ͨͨ������ȡ30%�����ѡ���
// �޸������ѣ�WTOó�׼���10%˰�� By server
//������־��¼,�����ѯ by lsxk@hsbbs 2007/7/29

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"ͨ����"NOR, ({"tongbao xiang", "xiang"}));
        set("long",
               "����ֻ���Դ�ȡ����ͨ������������,�����ͨ������������������\n"+
               HIG"\n    �鿴�����ڵ�ͨ������: "HIR"chakan tongbao xiang\n"+
               HIG"    ��ͨ��: "HIR"cun <����> ͨ�� in tongbao xiang\n"+
               HIG"    ȡͨ��: "HIR"qu <����> ͨ�� from tongbao xiang\n"NOR);
       set("unit", "ֻ");
        set("weight", 10);
       set("treasure", 1);
     set("credit",1);
}

void init()
{
    add_action("do_qu","qu");
    add_action("do_cun","cun");
    add_action("do_check","chakan");
}

int do_check(string arg)
{
    int i;
    i = (int)this_object()->query("SJ_Credit");

    if (!arg) return 0;
    if (arg!="tongbao xiang" && arg!="xiang") return 0;
    if (!i) return notify_fail("ͨ���������ɶ������û�С�\n");

    return notify_fail(HIY"ͨ�����������"+HIW+chinese_number(i)+HIY+"������ͨ����\n"NOR);
}

int do_qu(string arg)
{
    int i,credit_stored,p_credit;
    string str;
    object ob = this_object();
    object me = this_player();
    credit_stored = (int)ob->query("SJ_Credit");
    p_credit= (int)me->query("SJ_Credit");

    if (!arg) return notify_fail("��Ҫȡʲô?\n");

    if( !sscanf(arg, "%d ͨ�� from %s",i,str) )
        return notify_fail("��Ҫ������ȡʲô����?\n");

    if(str!="tongbao xiang" && str!="xiang")
        return notify_fail("��Ҫ������ȡ����?\n");

    if(!credit_stored)
        return notify_fail("����Ϊ����ħ��ʦ����ƾ��ȡͨ����\n");

    if(i>credit_stored)
        return notify_fail("��������ô��ͨ��ô��\n");
        
    if(i<credit_stored)
        return notify_fail("Sorry��������齣ͨ������һ��ȡ�ꣿ\n");

    if(i<=0)
        return notify_fail("��˯����ô��ʱ�仹�磬��ȥ˯˯��\n");

    ob->add("SJ_Credit",-0);
    me->add("SJ_Credit",i*10/10);


    log_file( "static/CREDIT_BOX_LOG",sprintf(HIG"%s(%s) ֮ǰ:%d | ����:%d | ȡ��:%d | ��ʧ:%d | ����:%d | ����:%d."NOR, me->name(),me->query("id"),p_credit,credit_stored,i,i/5,(int)me->query("SJ_Credit"), (int)ob->query("SJ_Credit")));

    message_vision(HIG"$N������$n"HIG"�����˼��£���Ȼ�ͳ���"+HIR+chinese_number(i*10/10)+HIG+"��"+HIW+"����ͨ��"HIG"��\n"+
                "����$Nȴ��ɥ�ķ�����"+HIM+chinese_number(i-i*10/10)+HIG+"��"+HIW+"�齣ͨ��"HIG"�������˷���Ͳ������ˡ�\n"NOR,me,ob);
    destruct(ob);
    return 1;
}

int do_cun(string arg)
{
    int i, j, credit_restored;
    string str;
    object ob = this_object();
    object me = this_player();

    if(!me->query("SJ_Credit"))
        return notify_fail("�����������ڵ�ͨ���ö�Ŷ������\n");

    j = (int)me->query("SJ_Credit");
    credit_restored = (int)ob->query("SJ_Credit");

    if (!arg) return notify_fail("��Ҫ��ʲô?\n");

    if( !sscanf(arg, "%d ͨ�� in %s",i,str) )
        return notify_fail("��Ҫ��ʲô�����������?\n");

    if(str!="tongbao xiang" && str!="xiang")
        return notify_fail("��Ҫ�浽����ȥ��?\n");

    if(i<=0)
        return notify_fail("��˯����ô��ʱ�仹�磬��ȥ˯˯��\n");

    if(i>j)
        return notify_fail("������ô��ͨ��ô��\n");

    message_vision(HIC"ֻ��$N͵͵�����ش���������"HIY+chinese_number(i)+HIC"��"HIW"����ͨ��"HIC"����"+
                  "����$n"HIC"��\n"NOR,me,ob);
   me->add("SJ_Credit",-i);
   ob->add("SJ_Credit",i);
   

    log_file( "static/CREDIT_BOX_LOG",sprintf(HIR"%s(%s) ֮ǰ:%d | ����:%d | ����:%d | ����:%d | ����:%d."NOR, me->name(), me->query("id"),j,credit_restored,i,(int)me->query("SJ_Credit"),(int)ob->query("SJ_Credit")));

   return 1;
}
