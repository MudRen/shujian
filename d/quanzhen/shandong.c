//By Jpei ����������

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��ɽɽ��");
        set("long", @LONG
����������������ǰ���޵�ɽ����������������һ����(hua)����д�ż�־������ġ�������ʦ����������
"ԭ�������������죬̫��׿�������ڣ���ʥϮ���������Դ����ȷ������ɣ�������أ��󿪶����ա�
������̣��������ˡ�Ȼ��˳����¡����ʱ���裬ȥʥ��Զ����ⲻ���������ȵ�������������֦Ҷ��������
��������ɢ����֮���ӣ�������֮���飬������Դ��������ɫ����Ϳ�յף��������������ʥ�˸��𣬾���Ԫ
һ��֮����������£�Ӧ��������֮�ᣬ��ͦ���ڶ������������潨�ڳж���ά��Ŧ��������ʵ������¼�ԡ�
��׶��¶����ظ����ɡ�������ʦ������Ҳ��������
    �����Ǹ��񰸣����ż������ؾ��䣬����һ�ѡ����Ǳ������������˳���Ⱦ���������ࡣ
LONG);
        set("exits", ([
                "out" : __DIR__"xiaolu3",
        ]));
        set("item_desc", ([
        	"hua": YEL "������һ�������ʿ�ı�Ӱ��������ʲô��"
                       "ò�����е���һ��ָ���죬\n                                         �������š�" HIR "��"
                       "������" NOR + YEL "�������֡�\n" NOR,
        ]) );
        set("paper_count", 1);
        setup();
}

void init()
{
        add_action("do_ketou", "ketou");
        add_action("do_fan","fankan");
}

int do_ketou(string arg)
{
        object sword;
        object me = this_player();
        
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");


        if ( !(me->query("family/family_name")=="ȫ���") || me->query_temp("get_sword") ) 
                return notify_fail("�㿴���������˵Ļ���������������Ⱥ��������µľ�����ɣ����ɵð���һ�ݡ�\n"); 
                
        if ( me->query("qi") <= 50)
        	      return notify_fail("���㵱ǰ������״����ȥ��Ϣ�ɡ�"); 
        	      
       sword= new(BINGQI_D("sword/qixing-jian"));
  
       if( me->query_temp("ketou") && arg =="����")
       {
            message_vision(HIG"$N����ǰȥ�����������İγ����Ǳ�����\n"NOR,me);
            sword->move(me);
            me->set_temp("get_sword",1);
            return 1;
         }
          else
          {
             message_vision("$N��������������ǰ�������Ϲ���������������ʦ�������������ͷ��\n", me);
             me->add_temp("ketou", 1);
             return 1;
          }
 }

//���칦quest�Ĵ�����
//��������Ҳ������ô���õ�

int do_fan(string arg)
{
        object paper;
        object me = this_player();

        if (!arg || arg != "���ؾ���")
                return notify_fail("��Ҫ��ʲô��\n");

        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
   
        if ( !(me->query("family/family_name")=="ȫ���") ) 
                return notify_fail("������ķ����˼�ҳ������������������֮������ֻ����������������˽⣬��Ȼ��ζ��\n"); 
               
       if ( !me->query_temp("ketou")  ) 
                return notify_fail("�㷭���˼�ҳ������������������֮����ֻ��������ޱȡ�\n");        

       if ( query("paper_count") <1  ) 
                return notify_fail("�㷭���˼�ҳ������������������֮����ֻ��������ޱȡ�\n");        
 
        if ( me->query_skill("xiantian-gong", 1)>=300 
             && me->query_skill("taoism", 1)>=200 
             && me->query_skill("quanzhen-jianfa", 1)>=300 
             && random(50) >=25  
             && !me->query_temp("quanzhen/force")
             && !me->query("quanzhen/force") ) 
        {
                paper=new(__DIR__"obj/xtg_book");
                if ( !paper ) return 1;

                add("paper_count", -1);
                me->set_temp("quanzhen/force", 1);

                message_vision(HIR"$N��ϸ�ķ����Ŷ������ص�ѧ���䣬��Ȼ���㷢������һ�����ƺ�����һС��˿�\n"NOR,me);
                write(MAG"����ϸ�Ľ�˿����һ����������������ļ����������ķ����ƺ������칦һ����У���ȴ������¡�\n"NOR);
                message_vision("$N��æ�������պá�\n",me);
                paper->move(me, 1);
              return 1;
        } 
       else  
            {   me->add_temp("ketou",-1);
              message_vision("$N����ķ����˼�ҳ������������������֮������ֻ����������������˽⣬��Ȼ��ζ��\n",me); 
              return 1;
              }

}

