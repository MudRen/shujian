int main(object me)
{
    object *all_objs;
    int size;

    all_objs = objects();
    size = sizeof(all_objs);

    tell_object(me,sprintf("内存中一共有：%d 个物件。\n",size));
    return 1;
}  
