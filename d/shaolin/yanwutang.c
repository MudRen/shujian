inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ��ƫ��������Ұ���һЩ��ʯ����ľ׮���������ߡ���λɮ������
�������������ϰ�͹��ƽ�����Ǵ���ɮ��̤���ĺۼ����������������������
��ɮ���������ڡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"luohan5",
            "west" : __DIR__"wstang1",
]));
        set("objects", ([
                CLASS_D("shaolin") + "/xuan-can":1 ]) );
        set("valid_startroom", 1);
        set("coor/x",-20);
  set("coor/y",280);
   set("coor/z",120);
   setup();
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}
int valid_leave(object me, string dir)
{
	object *obj;

	if (me->query("family/family_name") != "������" &&dir=="west"){
         if (present("xuancan dashi", environment(me)))
             return notify_fail("���Ѵ�ʦ��ס��˵������ɮ���������صأ����ɵ��Ӳ������롣\n");
         else
             return notify_fail("һλ��ɮ��Ȼ�ӱ������˳�������ס����˵������ɮ���������صأ����ɵ��Ӳ������롣\n����ͣ�������ˣ���λ��ɮһ���֣����˻���������\n");
}
 obj = filter_array(deep_inventory(me),(:get_object:));
      if( sizeof(obj) && dir=="west" ) {
        tell_object(me,"��һ��С�ģ����ż����ˡ�\n");
        obj[0]->move(environment(me));
        me->unconcious();
return 0;
    }
if(me->query("family/family_name")=="������"&&me->query("family/generation")>37&&dir=="west"&&!wizardp(me))
return notify_fail("һλ��ɮ��Ȼ�ӱ������˳�������ס����˵������ɮ���������صأ��ʹ����Ӳ������롣\n");
return ::valid_leave(me, dir);
}
