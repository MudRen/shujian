//Created by Zhuifeng@SJFY 2010/8/16

#include <ansi.h>
#define JADE    "/d/zhiye/obj/othermaterial" //��
#define KUANGSHI    "/d/zhiye/obj/kuangshi" //��
#define BULIAO    "/d/zhiye/obj/buliao" //����
inherit SPEC;
void create()
{
        set_name(HIR"��˼��"NOR, ({ "xiangsi dou","dou"}) );
        set_weight(10);
                set("unit", "��");
                set("long", "�ʼ����ꡢɫ����Ѫ���������������࣬�������������������ɫ��Ө��������ɫ�������μ���·����Ϊ���ġ����Ρ�\n"
                            "����Ǵ�����С�ģ�������ӡ����˵��������˼֮����ˣ��������£����Ի��⣬����������ɣ�������֮����˼֮�⡣\n"
                             "�������������˼������İ���(Airen)�ɣ�\n");
                set("value", 10);
                set("material", "wood");
                set("no_drop", "������ܶ�����Щ����������˼֮�顣\n");
                set("no_get", "��������ܹ����ñ�����˼֮�࣬�ֺα��ݼ�����˼֮���ء�\n");
                set_weight(50);
                set("value",3000);
                set("treasure",1);
                set("desc","�춹���Ϲ�����������֦��Ը�����ߢ����������˼��");
                set("credit",1000);    

       setup();
}
void init()
{
        add_action("do_think", "think");
}

int do_think(string arg)
{        
       object me = this_player();
       object obj;
       string str = "";
       int i = random(1);

       if(arg!="airen")
          return notify_fail(HIM"����˼��˭��\n"NOR);                    

       switch(i) {                          
                        case 1:         
                                obj = new (KUANGSHI);
                                obj->set_level(9+random(1));
                                obj->set_level(9+random(1)); 
                                break;       
 
                        case 0:         
                                obj = new (JADE);
                                obj->set("secret_obj",1);
                                obj->set_level(5+random(1));
                                str = "��Ʒ";
                                str += "��"; 
                                break;        
                                break;                                                           
                        default:return 1;
                }
      	obj->move(this_player());

        CHANNEL_D->do_channel( this_object(), "rumor",sprintf(HIM"��˵%s��"HIY"��˼�춹"HIM"�л����һ"+obj->query("unit")+obj->name()+"��", me->name(1)));
        message_vision("$N���������˾þõĳ�˼.......\n",me); 
               
        destruct(this_object());
        return 1;               
}

