// /u/jpei/guiyun/qianting.c
// ����ת��ʦ���Ĵ��� Modified by Numa

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","ǰ��");
        set("long",@LONG
���ǹ���ׯ��ǰ����ƽ���д����˶���������С����г��軪����������
����������˼��
LONG
);
        set("objects",([
                __DIR__"npc/lugy" :     1,
                __DIR__"npc/zhuangding" : 1,
        ]));  
        set("exits",([
                "east" : __DIR__"shiqiao",
                "west" : __DIR__"zhongting",
        ]) );
        set("no_clean_up",0);
        setup();
        "/clone/board/guiyun_b.c"->foo();
}

void init()
{
        object me = this_player();

        if (me->query("family/family_name")=="�һ���")
        {
                if ((int)me->query("family/generation")==2)
                {
                        if ((int)me->query_skill("bihai-chaosheng",1) < 130 && me->query_skill("bihai-chaosheng",1) >= 80)
                        {
                                me->set("family/master_id","lu chengfeng");
                                me->set("family/master_name","½�˷�");
                                me->set("family/generation",3);
                		me->set("title","�һ�������������");
                                write( HIY "�������ı̺������ȼ�С��һ����ʮ����ϵͳ�ѽ���ת��Ϊ�һ������������ӡ�\n" NOR);
                                return;
                        }
                        else if ((int)me->query_skill("bihai-chaosheng",1) < 80)
                        {
                                me->set("family/master_id","lu guanying");
                                me->set("family/master_name","½��Ӣ");
                                me->set("family/generation",4);
                		me->set("title","�һ������Ĵ�����");
                                write( HIY "�������ı̺������ȼ�С�ڰ�ʮ����ϵͳ�ѽ���ת��Ϊ�һ������Ĵ����ӡ�\n" NOR);
                                return;
                        }
                }
                else if ((int)me->query("family/generation")==3)
                {
                        if ((int)me->query_skill("bihai-chaosheng",1) < 80)
                        {
                                me->set("family/master_id","lu guanying");
                                me->set("family/master_name","½��Ӣ");
                                me->set("family/generation",4);
                		me->set("title","�һ������Ĵ�����");
                                write( HIY "�������ı̺������ȼ�С�ڰ�ʮ����ϵͳ�ѽ���ת��Ϊ�һ������Ĵ����ӡ�\n" NOR);
                                return;
                        }
                }
        }
}
