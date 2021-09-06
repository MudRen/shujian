#include <ansi.h>
inherit ROOM;
string* obj = ({
       BINGQI_D("gangzhang"),
       BINGQI_D("feihuangshi"),
       MISC_D("fire"),
       BINGQI_D("changbian"),
       ARMOR_D("armor"),
       BINGQI_D("gangjian"),
       BINGQI_D("tiegun"),
       FOOD_D("hulu"),
       BINGQI_D("blade"),
       ARMOR_D("changpao"),
       __DIR__"obj/shezhang",
       __DIR__"obj/book1",
       __DIR__"obj/book2",
       __DIR__"obj/book3",
       __DIR__"obj/book5",
       __DIR__"obj/shepi",
       __DIR__"obj/yao",
       __DIR__"obj/yao1",
       __DIR__"obj/yao2",       
});

void create()
{
        set("short", "������");
        set("long", @LONG
��һ���ű��ŵ�һ��ùζ����������������������ҫ�£��㿴����
�����ݵĻҳ����ɶѳɶѵ���Ʒ����������䷿�䡣��������Ϊʲô��
�����뿪ʱ������Щ��ƷҲ���ߡ�
LONG);
        set("exits", ([
              "east" : __DIR__"kongdi",
        ]));
        setup(); 
}

void init()
{
        add_action("do_find", "find");
        add_action("do_find", "zhao");
        add_action("do_find", "fan");
}

int found(object me)
{
        object ob = new( obj[random(sizeof(obj))] );
if (ob) {
 ob->move(me);
        message_vision("$N���˰��죬�ҵ���" + ob->query("name") + "��\n", me);
        me->set_temp("baituo_find", 1);
}
        return 1;
}

int do_find()
{
       object me = this_player();
       if( (int)me->query_temp("baituo_find") ) 
                return notify_fail("���Ѿ����˶����ˣ��߰ɡ�\n");
       if (me->query_skill("hamagong", 1) && 
           me->query_skill("poison", 1) > 30){
                message_vision("$N���ű�������Ʒ�����ҷ��š�\n", me);
                found(me);    
                }
       else if (me->query_skill("poison", 1) > 50){
                message_vision("$N���ű�������Ʒ�����ҷ��š�\n", me);
                if(random((int)me->query("kar")) < 15){
                     write("�����˿�����ͻȻ����ͷ��һ��ѣ�Ρ�\n");
                     me->unconcious();
                     }
                else found(me);    
                }
       else { 
                message_vision("$N���ű�������Ʒ�����ҷ��š�\n", me);
                write("�����˿�����ͻȻ����ͷ��һ��ѣ�Ρ��������ã����ж��ˣ�\n");
                me->apply_condition("snake_poison", me->query_condition("snake_poison")+22);
                me->unconcious();
                }
       return 1; 
}
